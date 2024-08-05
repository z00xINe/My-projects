//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;
int turn = 1;
char board[6][7];
//---------------------------------------------------------------------------
bool TForm2::is_winner()
{
	for (int i = 5; i >= 0 ; --i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if ((board[i][j] == 'X' && board[i][j+1] == 'X' && board[i][j+2] == 'X' && board[i][j+3] == 'X') ||
				(board[i][j] == 'O' && board[i][j+1] == 'O' && board[i][j+2] == 'O' && board[i][j+3] == 'O'))
				return true;

			if ((board[i][j] == 'O' && board[i+1][j] == 'O' && board[i+2][j] == 'O' && board[i+3][j] == 'O') ||
				(board[i][j] == 'X' && board[i+1][j] == 'X' && board[i+2][j] == 'X' && board[i+3][j] == 'X'))
				return true;

			if ((board[i][j] == 'X' && board[i-1][j+1] == 'X' && board[i-2][j+2] == 'X' && board[i-3][j+3] == 'X') ||
				(board[i][j] == 'O' && board[i-1][j+1] == 'O' && board[i-2][j+2] == 'O' && board[i-3][j+3] == 'O'))
				return true;
		}
	}
	return false;
}
//--------------------------------------------------------------------------
bool TForm2::is_draw(int t)
{
	return (t == 42 && !is_winner());
}
//--------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner):TForm(Owner)
{
	Symbol->Text = "X";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonClick1(TObject *Sender)
{
	if(Button1->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button1->Text = "X";
			board[5][0] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button1->Text = "O";
			board[5][0] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if(turn > 42)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button8->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button8->Text = "X";
			board[4][0] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button8->Text = "O";
			board[4][0] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if(turn > 42)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button15->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button15->Text = "X";
			board[3][0] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button15->Text = "O";
			board[3][0] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if(turn > 42)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button22->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button22->Text = "X";
			board[2][0] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button22->Text = "O";
			board[2][0] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if(turn > 42)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button29->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button29->Text = "X";
			board[1][0] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button29->Text = "O";
			board[1][0] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if(turn > 42)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button36->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button36->Text = "X";
			board[0][0] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button36->Text = "O";
			board[0][0] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if(turn > 42)
			winnerLabel->Text = "Game over!!!!!!";
	}

	turn++;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonClick2(TObject *Sender)
{
	if(Button2->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button2->Text = "X";
			board[5][1] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button2->Text = "O";
			board[5][1] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if(turn > 42)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button9->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button9->Text = "X";
			board[4][1] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button9->Text = "O";
			board[4][1] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button16->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button16->Text = "X";
			board[3][1] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button16->Text = "O";
			board[3][1] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button23->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button23->Text = "X";
			board[2][1] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button23->Text = "O";
			board[2][1] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button30->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button30->Text = "X";
			board[1][1] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button30->Text = "O";
			board[1][1] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button37->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button37->Text = "X";
			board[0][1] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button37->Text = "O";
			board[0][1] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	turn++;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonClick3(TObject *Sender)
{
	if(Button3->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button3->Text = "X";
			board[5][2] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button3->Text = "O";
			board[5][2] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button10->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button10->Text = "X";
			board[4][2] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button10->Text = "O";
			board[4][2] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button17->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button17->Text = "X";
			board[3][2] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button17->Text = "O";
			board[3][2] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button24->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button24->Text = "X";
			board[2][2] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button24->Text = "O";
			board[2][2] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button31->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button31->Text = "X";
			board[1][2] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button31->Text = "O";
			board[1][2] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button38->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button38->Text = "X";
			board[0][2] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button38->Text = "O";
			board[0][2] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	turn++;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonClick4(TObject *Sender)
{
	if(Button4->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button4->Text = "X";
			board[5][3] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button4->Text = "O";
			board[5][3] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button11->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button11->Text = "X";
			board[4][3] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button11->Text = "O";
			board[4][3] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button18->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button18->Text = "X";
			board[3][3] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 42)
		{
			Button18->Text = "O";
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button25->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button25->Text = "X";
			board[3][3] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button25->Text = "O";
			board[3][3] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button32->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button32->Text = "X";
			board[2][3] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button32->Text = "O";
			board[2][3] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button39->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button39->Text = "X";
			board[1][3] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button39->Text = "O";
			board[1][3] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	turn++;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonClick5(TObject *Sender)
{
	if(Button5->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button5->Text = "X";
			board[5][4] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button5->Text = "O";
			board[5][4] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button12->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button12->Text = "X";
			board[4][4] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button12->Text = "O";
			board[4][4] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button19->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button19->Text = "X";
			board[3][4] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button19->Text = "O";
			board[3][4] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button26->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button26->Text = "X";
			board[2][4] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button26->Text = "O";
			board[2][4] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button33->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button33->Text = "X";
			board[1][4] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button33->Text = "O";
			board[1][4] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button40->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button40->Text = "X";
			board[0][4] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button40->Text = "O";
			board[0][4] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	turn++;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonClick6(TObject *Sender)
{
	if(Button6->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button6->Text = "X";
			board[5][5] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button6->Text = "O";
			board[5][5] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button13->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button13->Text = "X";
			board[4][5] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button13->Text = "O";
			board[4][5] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button20->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button20->Text = "X";
			board[3][5] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button20->Text = "O";
			board[3][5] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button27->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button27->Text = "X";
			board[2][5] = 'O';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button27->Text = "O";
			board[2][5] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button34->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button34->Text = "X";
			board[1][5] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button34->Text = "O";
			board[1][5] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button41->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button41->Text = "X";
			board[0][5] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button41->Text = "O";
			board[0][5] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	turn++;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonClick7(TObject *Sender)
{
	if(Button7->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button7->Text = "X";
			board[5][6] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button7->Text = "O";
			board[5][6] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button14->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button14->Text = "X";
			board[4][6] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button14->Text = "O";
			board[4][6] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button21->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button21->Text = "X";
			board[3][6] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button21->Text = "O";
			board[3][6] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button28->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button28->Text = "X";
			board[2][6] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button28->Text = "O";
			board[2][6] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button35->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button35->Text = "X";
			board[1][6] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button35->Text = "O";
			board[1][6] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	else if(Button42->Text.IsEmpty())
	{
		if (turn % 2 != 0 && turn < 43)
		{
			Button42->Text = "X";
			board[0][6] = 'X';
			Symbol->Text = "O";
		}
		else if (turn % 2 == 0 && turn < 43)
		{
			Button42->Text = "O";
			board[0][6] = 'O';
			Symbol->Text = "X";
		}

		if (is_winner())
		{
			winnerLabel->Text = "You WON!!!!!!";
		}

		else if (is_draw(turn))
		{
			winnerLabel->Text = "Draw!!!!!!!";
		}

		else if (turn > 41)
			winnerLabel->Text = "Game over!!!!!!";
	}

	turn++;
}
//---------------------------------------------------------------------------------
