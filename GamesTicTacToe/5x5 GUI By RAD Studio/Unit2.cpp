//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;
int turn = 1;
AnsiString board[5][5];
//---------------------------------------------------------------------------
void TForm2::is_winner()
{
	int win_x = 0, win_o = 0;

	board[0][0] = Button21->Text;
	board[0][1] = Button22->Text;
	board[0][2] = Button23->Text;
	board[0][3] = Button24->Text;
	board[0][4] = Button25->Text;
	board[1][0] = Button16->Text;
	board[1][1] = Button17->Text;
	board[1][2] = Button18->Text;
	board[1][3] = Button19->Text;
	board[1][4] = Button20->Text;
	board[2][0] = Button11->Text;
	board[2][1] = Button12->Text;
	board[2][2] = Button13->Text;
	board[2][3] = Button14->Text;
	board[2][4] = Button15->Text;
	board[3][0] = Button6->Text;
	board[3][1] = Button7->Text;
	board[3][2] = Button8->Text;
	board[3][3] = Button9->Text;
	board[3][4] = Button10->Text;
	board[4][0] = Button1->Text;
	board[4][1] = Button2->Text;
	board[4][2] = Button3->Text;
	board[4][3] = Button4->Text;
	board[4][4] = Button5->Text;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// Rows wins for 'X'
			if (board[i][j] == 'X' &
			board[i][j+1] == 'X' &
			board[i][j+2] == 'X')
				win_x++;

			// Cols wins for 'X'
			if (board[i][j] == 'X' &
			board[i+1][j] == 'X' &
			board[i+2][j] == 'X')
				win_x++;

			// Diagonal for 'X'
			if (board[i][j] == 'X' &
			board[i+1][j+1] == 'X' &
			board[i+2][j+2] == 'X')
				win_x++;

			// Rows wins for 'O'
			if (board[i][j] == 'O' &
			board[i][j+1] == 'O' &
			board[i][i+2] == 'O')
				win_o++;

			// Cols wins for 'O'
			if (board[i][j] == 'O' &
			board[i+1][j] == 'O' &
			board[i+2][i] == 'O')
				win_o++;

			// Diagonal for 'O'
			if (board[i][j] == 'O' &
			board[i+1][j+1] == 'O' &
			board[i+2][j+2] == 'O')
				win_o++;
		}
	}

	AnsiString tmp = IntToStr(win_x) + " : " + IntToStr(win_o);
	winnerLabel->Text = tmp;
	return;
}
//--------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner):TForm(Owner)
{
	Symbol->Text = "X";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonClick(TObject *Sender)
{
	TButton* clickedButton = dynamic_cast<TButton*>(Sender);

	if (turn % 2 != 0 && turn < 25)
	{
		clickedButton->Text = "X";
		Symbol->Text = "O";
	}
	else if (turn % 2 == 0 && turn < 25)
	{
		clickedButton->Text = "O";
		Symbol->Text = "X";
	}

	else
		is_winner();

	turn++;
}
//---------------------------------------------------------------------------
