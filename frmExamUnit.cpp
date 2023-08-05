//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frmExamUnit.h"
#include "DMUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmKruger *frmKruger;
//---------------------------------------------------------------------------
__fastcall TfrmKruger::TfrmKruger(TComponent* Owner): TForm(Owner)
{
	  //set which page to open first
	  PageControl->ActivePage = tbsFive;
}
//---------------------------------------------------------------------------

//====================== auto-connect to DB =================
void __fastcall TfrmKruger::pnlConnectClick(TObject *Sender)
{
	//fetching the database
	AnsiString DBsource = GetCurrentDir();
	DBsource.Delete(DBsource.LastDelimiter("\\"), 40);
	DBsource.Delete(DBsource.LastDelimiter("\\"), 40);
	AnsiString conn = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=";
	conn += DBsource + "\\AppData\\KrugerPark.accdb";
	conn += ";Mode=ReadWrite;Persist Security Info=False";

	//connect the database
	DMod->ADOConn->LoginPrompt = false;
	DMod->ADOConn->Connected = false;
	DMod->ADOConn->ConnectionString = conn;
	try
	{
		DMod->ADOConn->Connected = true;

		pnlConnect->Color = clYellow;
		pnlConnect->Caption = "CONNECTED!";

		//populate the dbGrid
		AnsiString SQLstring = "SELECT AccomodationType, CampCode, BaseRate, ";
		SQLstring += "NrUnits FROM TarrifRates";

		DMod->ADOdsTarrifs->Connection = DMod->ADOConn;
		DMod->ADOdsTarrifs->Active = false;
		DMod->ADOdsTarrifs->CommandText = SQLstring;
		DMod->ADOdsTarrifs->Active = true;

		DMod->DSTarrifs->DataSet = DMod->ADOdsTarrifs;

		dbgrdData->DataSource = DMod->DSTarrifs;
	}
	catch(...)          			//catch errors when connecting the database
	{
		ShowMessage("Can't connect!");
	}
}
//===========================================================================
//---------------------------- tbsFIVE ---------------------------------------
void __fastcall TfrmKruger::btnTotUnitsClick(TObject *Sender)
{
	//calculating the sum of number of units
	AnsiString SQLstring = "SELECT SUM(NrUnits) AS [Total of all units]";
	SQLstring += "FROM TarrifRates";

	DMod->ADOdsTemp->Connection = DMod->ADOConn;
	DMod->ADOdsTemp->Close();
	DMod->ADOdsTemp->CommandText = SQLstring;
	DMod->ADOdsTemp->Active = true;

	DMod->DSTemp->DataSet = DMod->ADOdsTemp;

	dbgrdData->DataSource = DMod->DSTemp;
}
//---------------------------------------------------------------------
void __fastcall TfrmKruger::btnTotRecsClick(TObject *Sender)
{
	//count the number of records
	AnsiString SQLstring = "SELECT COUNT(NrUnits) AS [Total number of records] ";
	SQLstring += "FROM TarrifRates";

	DMod->ADOdsTemp->Connection = DMod->ADOConn;
	DMod->ADOdsTemp->Close();
	DMod->ADOdsTemp->CommandText = SQLstring;
	DMod->ADOdsTemp->Active = true;

	DMod->DSTemp->DataSet = DMod->ADOdsTemp;

	dbgrdData->DataSource = DMod->DSTemp;
}
//----------------------------------------------------------------------
void __fastcall TfrmKruger::btnAvgClick(TObject *Sender)
{
	//calculate the average
	AnsiString SQLstring = "SELECT CampCode, ROUND(AVG(NrUnits), 1) AS [Average of units]";
	SQLstring += "FROM TarrifRates GROUP BY CampCode";

	DMod->ADOdsTemp->Connection = DMod->ADOConn;
	DMod->ADOdsTemp->Close();
	DMod->ADOdsTemp->CommandText = SQLstring;
	DMod->ADOdsTemp->Active = true;

	DMod->DSTemp->DataSet = DMod->ADOdsTemp;

	dbgrdData->DataSource = DMod->DSTemp;
}
//==============================(SQL)==================================
void __fastcall TfrmKruger::btnClientsSQLClick(TObject *Sender)
{
	/*Count all the clients that do have AddressLine2 missing and who joined
	(JoinDate) before 2011 */
	AnsiString SQLstring = "SELECT COUNT(*) AS [Clients who joined before 2011] FROM ";
	SQLstring += "Clients WHERE JoinDate < #2011/01/01# AND AddressLine2 IS NULL";

	DMod->ADOUseQuery1->Connection = DMod->ADOConn;
	DMod->ADOUseQuery1->Close();
	DMod->ADOUseQuery1->SQL->Add(SQLstring);
	DMod->ADOUseQuery1->Open();

	DMod->DSQuery1->DataSet = DMod->ADOUseQuery1;

	dbgrdData->DataSource = DMod->DSQuery1;
}
//=============================ADO Construct(Non-SQL)==========================
void __fastcall TfrmKruger::btnClientsNoSQLClick(TObject *Sender)
{
	/*Count all the clients that do have AddressLine2 missing and who joined
	(JoinDate) before 2011 */
	TDate JoinD;
	AnsiString address;
	int count = 0;

	DMod->ADOdsClients->Open();
	DMod->ADOdsClients->First();

	while (!DMod->ADOdsClients->Eof)
	{
		JoinD = DMod->ADOdsClients->FieldByName("JoinDate")->AsDateTime;
		address = DMod->ADOdsClients->FieldByName("AddressLine2")->AsAnsiString;

		if ((JoinD < StrToDate("2011/01/01")) && (address == ""))
		{
			count++;
		}
	}
	DMod->ADOdsClients->Next();

	ShowMessage("There are " +IntToStr(count) + " clients joined before 2011"
	+ " - NOT having a second address");
}
//============================ tbsSIX =======================================
void __fastcall TfrmKruger::tbsSixShow(TObject *Sender)       // OnSHOW()
{
	//connect the wildcard database
	DMod->ADOdsWildCard->Connection = DMod->ADOConn;
	DMod->ADOdsWildCard->Close();
	DMod->ADOdsWildCard->CommandText = "Select * From WildCard";
	DMod->ADOdsWildCard->Open();

	DBEdit1->DataSource = DMod->DSWildCard;
	DBEdit1->DataField = "Code";

	DBEdit4->DataSource = DMod->DSWildCard;
	DBEdit4->DataField = "SingleRate";

	DBEdit2->DataSource = DMod->DSWildCard;
	DBEdit2->DataField = "FullName";

	DBNavigator1->DataSource = DMod->DSWildCard;
}
//---------------------------------------------------------------------
void __fastcall TfrmKruger::btnIncreaseOneSessionPriceClick(TObject *Sender)
{
	//declaration
	float increasedRate, perc;

	//get the percentage and set a default of 15
	perc = InputBox("Increase percentage", "Please enter the percentage", 15).ToDouble();

	perc = perc / 100;

	//increase the rate
	DMod->ADOdsWildCard->Open();

	for (DMod->ADOdsWildCard->First(); !DMod->ADOdsWildCard->Eof;)
	{
		//get the current field
		float rate;

		rate = DMod->ADOdsWildCard->FieldByName("SingleRate")->AsFloat;

		increasedRate = rate + (rate * perc);

		DMod->ADOdsWildCard->Edit();
		DMod->ADOdsWildCard->FieldByName("SingleRate")->AsFloat = increasedRate;

		DMod->ADOdsWildCard->Next();
	}
	ShowMessage("Table have been UPDATED");

	DMod->ADOdsWildCard->First();
}
//---------------------------------------------------------------------
void __fastcall TfrmKruger::btnAddClientClick(TObject *Sender)
{
	// INSERT code
	AnsiString clientNum = 1000000;

	edtClientNr->Text = clientNum;

	DMod->ADOdsClients->Open();

	DMod->ADOdsClients->Insert();
	DMod->ADOdsClients->FieldByName("ClientNr")->AsAnsiString = clientNum;
	DMod->ADOdsClients->FieldByName("Surname")->AsAnsiString = edtSurname->Text;
	DMod->ADOdsClients->FieldByName("Initials")->AsAnsiString = edtInitials->Text;
	DMod->ADOdsClients->FieldByName("SAIDNum")->AsAnsiString = edtID->Text;
	DMod->ADOdsClients->FieldByName("JoinDate")->AsDateTime = Now();
	DMod->ADOdsClients->Post();

	DMod->ADOdsClients->Close();
	DMod->ADOdsClients->Open();

	clientNum = clientNum + 1;
}
//---------------------------------------------------------------------------
void __fastcall TfrmKruger::btnReportClick(TObject *Sender)
{
	// REPORT code
	AnsiString SQLString = "SELECT R.Surname + ' ' + R.Name AS Ranger, ";
	SQLString += "DateDiff('yyyy', R.DateAppointed, Date()) AS [Years employed]";
	SQLString += " , SUM(S.NumAnimals) AS [Animals Sighted] ";
	SQLString += "FROM Rangers R, Sightings S WHERE R.RangerID = S.RangerID ";
	SQLString += "GROUP BY R.Surname, R.Name, R.DateAppointed";

	DMod->ADOdsTemp->Connection = DMod->ADOConn;
	DMod->ADOdsTemp->Active = false;
	DMod->ADOdsTemp->CommandText = SQLString;
	DMod->ADOdsTemp->Open();

	//expansion of rank and date appoint
	SQLString = "SELECT R.Rank, R.Surname + ' ' + R.Name AS Ranger, R.DateAppointed,";
	SQLString += "DateDiff('yyyy', R.DateAppointed, Date()) AS [Years employed]";
	SQLString += " , SUM(S.NumAnimals) AS [Animals Sighted] ";
	SQLString += "FROM Rangers R, Sightings S WHERE R.RangerID = S.RangerID ";
	SQLString += "GROUP BY R.Rank, R.Surname, R.Name, R.DateAppointed";

	DMod->ADOdsTemp->Active = false;
	DMod->ADOdsTemp->CommandText = SQLString;
	DMod->ADOdsTemp->Open();

	//add heading
	AnsiString title, heading, line, record;

	title = "Rangers with years of employement";
	heading = "Rank \t Ranger \t DateAppointed \t Years employed \t Animals Sighted";
	line = "==========\t==========\t===========\t==========\t===========";

	lstReport->Items->Add(title);
	lstReport->Items->Add(line);
	lstReport->Items->Add(heading);
	lstReport->Items->Add(line);

	//add items to the listbox
	AnsiString rnk, init, initName, initSurn, initial, appointed, yearsEmployed, animalSighted;
	double average, total;

	double totalEmp = 0;
	double yearsEmp;
	int count = 0;

	int totalAnimals = 0;
	int animals;

	DMod->ADOdsTemp->First();
	for (int i = 0; i <= DMod->ADOdsTemp->RecordCount; i++)
	{
		rnk = DMod->ADOdsTemp->FieldByName("Rank")->AsAnsiString;

		init = DMod->ADOdsTemp->FieldByName("Ranger")->AsAnsiString;
		initName = init.SubString(1, init.Pos(" ") - 1);
		initSurn = init.SubString(init.Pos(" ") + 1, 1);

		initial = initName + ", " + initSurn;

		appointed = DMod->ADOdsTemp->FieldByName("DateAppointed")->AsAnsiString;
		yearsEmployed = DMod->ADOdsTemp->FieldByName("Years employed")->AsAnsiString;
		animalSighted = DMod->ADOdsTemp->FieldByName("Animals Sighted")->AsAnsiString;

		record = rnk + "\t" + initial + "\t" + appointed + "\t" + yearsEmployed;
		record += + "\t" + animalSighted;

		lstReport->Items->Add(record);

		DMod->ADOdsTemp->Next();

		//determine the total of the rangers' years of employement

		yearsEmp = DMod->ADOdsTemp->FieldByName("Years employed")->AsFloat;
		totalEmp += yearsEmp;
		count++;

		//the total of animals sighted

		animals = DMod->ADOdsTemp->FieldByName("Animals Sighted")->AsInteger;
		totalAnimals += animals;
	}
	//calculate the average
	double ave;

	ave = ave / count;

	//add the average of years employed and total of animals sighted to listbox
	lstReport->Items->Add(" ");
	lstReport->Items->Add("The average is " + FloatToStr(ave));
	lstReport->Items->Add("The total of animals sighted is " + IntToStr(totalAnimals));
}
//---------------------------------------------------------------------------










