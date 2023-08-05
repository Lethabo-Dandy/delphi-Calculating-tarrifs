//---------------------------------------------------------------------------

#ifndef frmExamUnitH
#define frmExamUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TfrmKruger : public TForm
{
__published:	// IDE-managed Components
	TPanel *pnlleft;
	TPanel *pnlTop;
	TImage *Image1;
	TPageControl *PageControl;
	TStatusBar *StatusBar;
	TTabSheet *tbsFive;
	TPanel *pnlBottom;
	TTabSheet *tbsSix;
	TDBGrid *dbgrdData;
	TLabel *Label1;
	TShape *Shape1;
	TPanel *pnlConnect;
	TLabel *Label2;
	TTabSheet *tbsSeven;
	TGroupBox *GroupBox1;
	TButton *btnTotUnits;
	TButton *btnTotRecs;
	TButton *btnAddClient;
	TPanel *Panel1;
	TEdit *edtInitials;
	TEdit *edtSurname;
	TEdit *edtID;
	TEdit *edtClientNr;
	TButton *btnIncreaseOneSessionPrice;
	TDBNavigator *DBNavigator1;
	TDBEdit *DBEdit4;
	TDBEdit *DBEdit2;
	TDBEdit *DBEdit1;
	TLabel *Label13;
	TLabel *Label12;
	TLabel *Label5;
	TLabel *Label4;
	TLabel *Label7;
	TLabel *Label6;
	TLabel *Label8;
	TLabel *Label9;
	TButton *btnReport;
	TListBox *lstReport;
	TLabel *Label17;
	TShape *Shape2;
	TShape *Shape3;
	TLabel *Label15;
	TLabel *Label10;
	TButton *btnAvg;
	TButton *btnClientsSQL;
	TButton *btnClientsNoSQL;
	void __fastcall pnlConnectClick(TObject *Sender);
	void __fastcall btnIncreaseOneSessionPriceClick(TObject *Sender);
	void __fastcall btnAddClientClick(TObject *Sender);
	void __fastcall btnReportClick(TObject *Sender);
	void __fastcall btnTotUnitsClick(TObject *Sender);
	void __fastcall btnTotRecsClick(TObject *Sender);
	void __fastcall btnAvgClick(TObject *Sender);
	void __fastcall btnClientsSQLClick(TObject *Sender);
	void __fastcall btnClientsNoSQLClick(TObject *Sender);
	void __fastcall tbsSixShow(TObject *Sender);




private:	// User declarations
public:		// User declarations

   AnsiString TempDesc;
   AnsiString TempCode;

	__fastcall TfrmKruger(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmKruger *frmKruger;
//---------------------------------------------------------------------------
#endif
