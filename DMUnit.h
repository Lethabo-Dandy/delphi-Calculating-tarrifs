//---------------------------------------------------------------------------

#ifndef DMUnitH
#define DMUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDMod : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *ADOConn;
	TADODataSet *ADOdsWildCard;
	TADODataSet *ADOdsTarrifs;
	TADODataSet *ADOdsSightings;
	TADODataSet *ADOdsRangers;
	TADODataSet *ADOdsClientWildCards;
	TADODataSet *ADOdsClients;
	TADODataSet *ADOdsCamptypes;
	TADODataSet *ADOdsCamps;
	TADODataSet *ADOdsAccTypes;
	TDataSource *DSWildCard;
	TDataSource *DSTarrifs;
	TDataSource *DSSightings;
	TDataSource *DSRangers;
	TDataSource *DSClientWildCards;
	TDataSource *DSClients;
	TDataSource *DSCampTypes;
	TDataSource *DSCamps;
	TDataSource *DSAccTypes;
	TADOQuery *ADOUseQuery1;
	TADOQuery *ADOUseQuery2;
	TDataSource *DSQuery1;
	TDataSource *DSQuery2;
	TWideStringField *ADOdsClientsClientNr;
	TWideStringField *ADOdsClientsSurname;
	TWideStringField *ADOdsClientsInitials;
	TWideStringField *ADOdsClientsSAIDNum;
	TDateTimeField *ADOdsClientsJoinDate;
	TWideStringField *ADOdsClientsAddressLine1;
	TWideStringField *ADOdsClientsAddressLine2;
	TWideStringField *ADOdsClientsCityTown;
	TWideStringField *ADOdsClientsPostalCode;
	TIntegerField *ADOdsClientsLoyaltyPoints;
	TWideStringField *ADOdsClientsWildCardNr;
	TADODataSet *ADOdsTemp;
	TDataSource *DSTemp;
	TADOCommand *ADOCommand;
private:	// User declarations
public:		// User declarations
	__fastcall TDMod(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMod *DMod;
//---------------------------------------------------------------------------
#endif
