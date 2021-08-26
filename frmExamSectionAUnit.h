//---------------------------------------------------------------------------

#ifndef frmExamSectionAUnitH
#define frmExamSectionAUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Samples.Spin.hpp>
//---------------------------------------------------------------------------
class TfrmExamFinSumAsses1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *pnlRight;
	TPageControl *pgctrlMain;
	TTabSheet *tbsQuestion1;
	TTabSheet *tbsQuestion2;
	TImage *Image1;
	TRadioGroup *rdgAnimals;
	TImage *imgAnimal;
	TStatusBar *stbInfo;
	TTabSheet *tbsQuestion3;
	TDBGrid *DBGridSightings;
	TLabel *Label11;
	TTabSheet *tbsQuestion4;
	TLabel *Label1;
	TLabel *lblPigLatinAnimal;
	TComboBox *cmbKeywordFilter;
	TButton *btnLoad;
	TCheckBox *ckbAnimalKeyword;
	TRichEdit *redOutput;
	TLabel *lblRecords;
	TBevel *Bevel1;
	TDBText *DBTextRangerID;
	TLabel *Label3;
	TLabel *lblRangerName;
	TDBText *DBTextRangerName;
	TLabel *lblRangerSurname;
	TDBText *DBTextRangerSurname;
	TLabel *Label4;
	TLabel *Label10;
	TDBGrid *grdSightings;
	TButton *btnCreateNewSightingId;
	TLabel *Label2;
	TLabel *Label12;
	TLabel *Label16;
	TComboBox *cmbYesNo;
	TLabel *Label15;
	TButton *btnSaveSighting;
	TLabel *lblSightingID;
	TComboBox *cmbAnimal;
	TSpinEdit *sedNumAnimals;
	TComboBox *cmbRangerDet;
	void __fastcall rdgAnimalsClick(TObject *Sender);
	void __fastcall tbsQuestion1Show(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall tbsQuestion3Show(TObject *Sender);
	void __fastcall tbsQuestion4Show(TObject *Sender);
	void __fastcall btnLoadClick(TObject *Sender);
	void __fastcall ckbAnimalKeywordClick(TObject *Sender);
	void __fastcall btnCreateNewSightingIdClick(TObject *Sender);
	void __fastcall btnSaveSightingClick(TObject *Sender);






private:	// User declarations
	AnsiString RangerName , RangerSurname;
	int rangerID;
	bool isVowel(char Let);
    AnsiString OneListLine;
	TStringList *lstRawData;

public:		// User declarations
	__fastcall TfrmExamFinSumAsses1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmExamFinSumAsses1 *frmExamFinSumAsses1;
//---------------------------------------------------------------------------
#endif
