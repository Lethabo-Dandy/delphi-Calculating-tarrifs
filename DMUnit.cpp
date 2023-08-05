//---------------------------------------------------------------------------


#pragma hdrstop

#include "DMUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDMod *DMod;
//---------------------------------------------------------------------------
__fastcall TDMod::TDMod(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
