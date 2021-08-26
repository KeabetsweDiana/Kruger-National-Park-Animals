//---------------------------------------------------------------------------

#include <vcl.h>
#include "jpeg.hpp"
#include "DMUnit.h"
#include "DateUtils.hpp"
#pragma hdrstop

#include "frmExamSectionAUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmExamFinSumAsses1 *frmExamFinSumAsses1;
//---------------------------------------------------------------------------
__fastcall TfrmExamFinSumAsses1::TfrmExamFinSumAsses1(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TfrmExamFinSumAsses1::btnLoadClick(TObject *Sender)
{
 // GIVEN Code
  redOutput->Lines->LoadFromFile("..\\..\\AppData\\SightingsListTabDel.txt");
  lblRecords->Caption = " Records processed - "  + IntToStr(redOutput->Lines->Count);

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// GetFieldByNr - GIVEN
AnsiString getFieldByNr(AnsiString aLine, int fieldNr, char delimiter)
{
	aLine += delimiter;
	int pos;
	AnsiString field;
	for (int i = 1; i <= fieldNr; i++) {
		pos = aLine.Pos(delimiter);
		field = aLine.SubString(1, pos - 1);
		aLine.Delete(1, pos);
	}

	return field;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


void __fastcall TfrmExamFinSumAsses1::tbsQuestion1Show(TObject *Sender)
{  // Question 1.1
   // (2) For every inncorrect setting -1

	 lblPigLatinAnimal->Font->Color = clOlive;
	 lblPigLatinAnimal->Font->Size = 18;
	 lblPigLatinAnimal->Font->Name = "Comic Sans";

}
//---------------------------------------------------------------------------

bool TfrmExamFinSumAsses1::isVowel(char Let)
{  // Question 1.2
   // (5)

   bool vowel;

   toupper(Let);

   switch(Let)
   {
	   case 'A':
	   case 'E':
	   case 'I':
	   case 'O':
	   case 'U':
	   vowel == true ;
	   break;
	   default:
	   vowel == false;

   }

	return vowel;
}

//---------------------------------------------------------------------------

void __fastcall TfrmExamFinSumAsses1::rdgAnimalsClick(TObject *Sender)
{ // Question 1.3
	 AnsiString animalName, pigLatinName;
	 char Let1, Let2;

	if(rdgAnimals->ItemIndex > 0)
	{
		animalName = rdgAnimals->Items->Strings[rdgAnimals->ItemIndex];
		Let1 = animalName[1];
		Let2 = animalName[2];

		if( isVowel(Let1) == false && isVowel(Let2) == true)
		{
		   animalName = animalName.Delete(1,1);
		   pigLatinName = animalName + Let1 += "ay";
		}

		if(isVowel(Let1) == false && isVowel(Let2) == false)
		{
			animalName = animalName.Delete(1,2);
            pigLatinName = animalName + Let1 + Let2 += "ay";
        }

		if( isVowel(Let1) == true)
		{
			animalName = animalName += "way";
		}

        lblPigLatinAnimal->Caption = pigLatinName;

	}

	 animalName = rdgAnimals->Items->Strings[rdgAnimals->ItemIndex];
	imgAnimal->Picture->LoadFromFile("\\..\\..AppData\\" + animalName + ".jpg");
  // (12)
  /*
  1. If a word starts with a consonant and a vowel,
	 put the first letter of the word at the end of the word and add "ay."
	 Example: Happy = appyh + ay = appyhay

  2. If a word starts with two consonants move the
	 two consonants to the end of the word and add "ay."
	 Example: Child = Ildch + ay = Ildchay

  3. If a word starts with a vowel add the word "way" at the end of the word.
	 Example: Awesome = Awesome +way = Awesomeway
  */

}
//---------------------------------------------------------------------------

 void __fastcall TfrmExamFinSumAsses1::ckbAnimalKeywordClick(TObject *Sender)
{  // Question 2.1
   // (17)

   //load the the data from the rich edit box into the Tstring list
   lstRawData->AddStrings(redOutput->Lines);

   AnsiString oneField;
   int AnimalSum = 0;

   for(int i = 0; i <lstRawData->Count; i++)
   {
	   OneListLine = lstRawData->Strings[i];
	   oneField = getFieldByNr(OneListLine, 3, '/t');

	   if(oneField.Pos(cmbKeywordFilter->Text.UpperCase()))
	   {
		  AnimalSum = AnimalSum + getFieldByNr(OneListLine,4,'\t').ToInt();
		  OneListLine = lstRawData->Strings[i];
		  redOutput->Lines->Add(OneListLine);
       }
   }

}

//---------------------------------------------------------------------------

void __fastcall TfrmExamFinSumAsses1::tbsQuestion3Show(TObject *Sender)
{
   // Question 3.1
   // Set up controls //3
	  DMod->ADOdsRangers->Active = true;

	  DBTextRangerID->DataSource = DMod->DSRangers;
	  DBTextRangerName->DataSource = DMod->DSRangers;
	  DBTextRangerSurname->DataSource = DMod->DSRangers;




   // Question 3.2
   // Create Dynamic navigator // 5
   TDBNavigator *RangerNav = new TDBNavigator(this);
   RangerNav->Parent = tbsQuestion3;
   RangerNav->Top = 105;
   RangerNav->Left = 15;
   RangerNav->DataSource = DMod->DSRangers;



   // Question 3.3
   // set up MD relationship    // 7
   DMod->ADOdsTemp->CommandText = "SELECT * FROM Sightings";
   DMod->ADOdsTemp->DataSource = DMod->DSRangers;

   DMod->ADOdsTemp->MasterFields = "RangerID";
   DMod->ADOdsTemp->IndexFieldNames = "RangerID";

   DMod->ADOdsTemp->Open();
   DMod->DSTemp->DataSet = DMod->ADOdsTemp;

   DBGridSightings->DataSource = DMod->DSTemp;


}

//---------------------------------------------------------------------------
void __fastcall TfrmExamFinSumAsses1::btnCreateNewSightingIdClick(TObject *Sender)
{
   // Question 4.1
   // (5)
   DMod->ADOUseQuery1->Close();
   DMod->ADOUseQuery1->Connection = DMod->ADOConn;
   DMod->ADOUseQuery1->SQL->Text = "SELECT MAX(SightingID) as lastval FROM Sightins";

   int lastID = DMod->ADOUseQuery1->FieldByName("lastval")->AsInteger;

   lastID++;
   lblSightingID->Caption = IntToStr(lastID);

}
//---------------------------------------------------------------------------

void __fastcall TfrmExamFinSumAsses1::btnSaveSightingClick(TObject *Sender)
{
	// Question 4.2
	// (15)

    DMod->ADOCommand->Connection = DMod->ADOConn;
AnsiString sql = "INSERT INTO sightings ";
sql += " (sightingid, sightingdate, Animal, numAnimals, young, rangerID) ";
sql += " VALUES (:sightid, :dte, :an, :num,:yng, :id)"; // 3
DMod->ADOCommand->CommandText = sql;
DMod->ADOCommand->Parameters->ParamByName("sightid")->Value =
lblSightingID->Caption.ToInt(); // 1
DMod->ADOCommand->Parameters->ParamByName("dte")->Value = Date(); // 1
DMod->ADOCommand->Parameters->ParamByName("an")->Value =
cmbAnimal->Text; // 1
DMod->ADOCommand->Parameters->ParamByName("num")->Value = sedNumAnimals->Value;// 1
bool young = false; // 2
if (cmbYesNo->Text == "Yes") {
young = true;
}
DMod->ADOCommand->Parameters->ParamByName("yng")->Value = young; // 1
DMod->ADOCommand->Parameters->ParamByName("id")->Value =
getFieldByNr(cmbRangerDet->Text,1,',').ToInt(); // 2

DMod->ADOCommand->Execute(); // 1
ShowMessage("Sighting recorded"); // 1
DMod->ADOdsSightings->Close();
DMod->ADOdsSightings->Open();
DMod->ADOdsSightings->Refresh(); // 1
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TfrmExamFinSumAsses1::FormShow(TObject *Sender)
{
 // Given code do not delete

	FormatSettings.DecimalSeparator = '.';
	FormatSettings.ShortDateFormat = "yyyy/mm/dd";
	FormatSettings.DateSeparator = '/';
	FormatSettings.TimeSeparator = ':';

	AnsiString DBsource = GetCurrentDir();
	DBsource.Delete(DBsource.LastDelimiter("\\"), 40);
	DBsource.Delete(DBsource.LastDelimiter("\\"), 40);
	AnsiString conn = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=";
	conn += DBsource + "\\AppData\\KrugerPark.accdb";
	conn += ";Mode=ReadWrite;Persist Security Info=False";

	DMod->ADOConn->LoginPrompt = false;

	DMod->ADOConn->Connected = false;
	DMod->ADOConn->ConnectionString = conn;
	try
	{
		DMod->ADOConn->Connected = true;
		DMod->ADOdsTarrifs->Open();
		DMod->ADOdsCamptypes->Open();
		DMod->ADOdsCamps->Open();
	}
   catch (EDatabaseError  *E)
	{
	  ShowMessage("Can't connect!");
	}

   pgctrlMain->ActivePageIndex = 0;

   lstRawData = new TStringList;
}
//---------------------------------------------------------------------------
void __fastcall TfrmExamFinSumAsses1::tbsQuestion4Show(TObject *Sender)
{
   // Given code

   DMod->ADOdsSightings->Active = true;
   grdSightings->DataSource = DMod->DSSightings;

   AnsiString SQLString = "Select str(RangerID) + \',\' + Surname as RDet from Rangers";



   DMod->ADOUseQuery1->Close();
   DMod->ADOUseQuery1->SQL->Clear();
   DMod->ADOUseQuery1->SQL->Add(SQLString);
   DMod->ADOUseQuery1->Open();

   cmbRangerDet->Items->Clear();
   for (DMod->ADOUseQuery1->First();!DMod->ADOUseQuery1->Eof;DMod->ADOUseQuery1->Next()) {
	 cmbRangerDet->Items->Add(DMod->ADOUseQuery1->FieldByName("RDet")->AsAnsiString);
   }

   cmbRangerDet->ItemIndex = 0;

}
//---------------------------------------------------------------------------



