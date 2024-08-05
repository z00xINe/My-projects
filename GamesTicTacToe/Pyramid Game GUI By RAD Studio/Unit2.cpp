//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;
int turn = 1;
//---------------------------------------------------------------------------
bool TForm2::is_winner()
{
	// Row Check
	if(!Button1->Text.IsEmpty() && Button1->Text == Button2->Text && Button1->Text == Button3->Text)
		return true;
	if(!Button4->Text.IsEmpty() && Button4->Text == Button2->Text && Button4->Text == Button3->Text)
		return true;
	if(!Button3->Text.IsEmpty() && Button3->Text == Button4->Text && Button3->Text == Button5->Text)
		return true;
	if(!Button6->Text.IsEmpty() && Button6->Text == Button7->Text && Button6->Text == Button8->Text)
		return true;

	// Col Check
	if(!Button3->Text.IsEmpty() && Button3->Text == Button5->Text && Button3->Text == Button9->Text)
		return true;

	// Digonal Check
	if(!Button1->Text.IsEmpty() && Button1->Text == Button6->Text && Button1->Text == Button9->Text)
		return true;
	if(!Button5->Text.IsEmpty() && Button5->Text == Button8->Text && Button5->Text == Button9->Text)
		return true;

	return false;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner):TForm(Owner)
{
	Symbol->Text='X';
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonClick(TObject *Sender)
{
	if (!is_winner() || turn < 25)
	{
		TButton* clickedButton = dynamic_cast<TButton*>(Sender);

		if (turn % 2 != 0)
		{
			clickedButton->Text='X';
			Symbol->Text='O';
		}
		else
		{
			clickedButton->Text='O';
			Symbol->Text='X';
		}
		turn++;

		if(is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!!!";
			return;
		}
	}
	else
	{
		if(turn >= 9 && !is_winner())
		{
			winnerLabel->Text = "Draw!!!!!!!!";
			return;
		}

		winnerLabel->Text = "Game over!!!!!!!";
		return;
	}

}
//---------------------------------------------------------------------------
