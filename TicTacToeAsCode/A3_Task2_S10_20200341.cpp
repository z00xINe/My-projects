// File name: A3_Task2_S10_20200341
// Author(s): Omar Amin
// ID(s): 20200341
// Section: 10
// Date: 14/12/2023

#include <bits/stdc++.h>

using namespace std;

class X_O_Board
{
private:
    static const int n_rows = 3, n_cols = 5;
    char board[3][5]{};
    int  n_moves = 0;
public:
    X_O_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over() const;
};

class Player
{
protected:
    string name;
    char symbol;
public:
    explicit Player (char symbol);
    Player (int order, char symbol);
    virtual void get_move(int& x, int& y);
    string to_string();
    char get_symbol() const;
};

class RandomPlayer: public Player
{
protected:
    int dimension;

public:
    RandomPlayer (char symbol, int dimension);
    void get_move(int& x, int& y) override;
};

class GameManager
{
private:
    X_O_Board* boardPtr;
    Player* players[2]{};

public:
    GameManager(X_O_Board*, Player* playerPtr[2]);
    void run();
};

X_O_Board::X_O_Board ()
{
    for (auto & i : board)
    {
        for (char & j : i)
        {
            j = 0;
        }
    }
}

bool X_O_Board::update_board (int x, int y, char mark){
    if (!(x < 0 || x > 2 || y < 0 || y > 4) && (board[x][y] == 0) &&
        ((x==0 && y==2) || ((x==1 && y==1) || (x==1 && y==2) || (x==1 && y==3)) || (x==2)))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }

    else
        return false;
}

void X_O_Board::display_board()
{
    for (int i=0; i<=2; i++)
    {
        cout << "\n";
        for (int j=0; j<=4; j++)
        {
            if ((i == 0 && j==2))
            {
                cout <<setw(20)<<" |"<< "(" << i << "," << j << ")" << setw(2) << board [i][j] << " |";
            }
            else if (i == 1 && j==1)
            {
                cout <<setw(11)<<" |"<< "(" << i << "," << j << ")" << setw(2) << board [i][j] << " |";
            }
            else if ((i == 1 && j==2) || (i == 1 && j==3) || (i == 2 && j==0) || (i == 2))
            {
                cout << "(" << i << "," << j << ")" << setw(2) << board [i][j] << " |";
            }
        }
        cout << "\n-----------------------------------------------";
    }
    cout << endl;
}

bool X_O_Board::is_winner()
{
    char row_win[5], col_win[3], diag_win[2];
    for (int i:{0, 1, 2})
    {
        if (i==1)
            row_win[i] = board[i][1] & board[i][2] & board[i][3];

        if (i==2)
            for(int j = 0,i=2;i<5;i++,j++)
            {
                row_win[i] = board[2][j] & board[2][j+1] & board[2][j+2];
            }
            col_win[i] = board[0][i] & board[1][i] & board[2][i];
    }
    diag_win[0] = board[0][2] & board[1][3] & board[2][4];
    diag_win[1] = board[0][2] & board[1][1] & board[2][0];

    for (int i:{0,1,2,3,4})
    {
        if ( (row_win[i] && (row_win[i] == board[1][2])) || (row_win[i] && (row_win[i] == board[2][2])) ||
             (col_win[i] && (col_win[i] == board[0][i])) )
        {return true;}
    }
    if ((diag_win[0] && diag_win[0] == board[2][4]) ||
        (diag_win[1] && diag_win[1] == board[2][0]))
    {return true;}
    return false;
}

bool X_O_Board::is_draw()
{
    return (n_moves == 9 && !is_winner());
}

bool X_O_Board::game_is_over () const
{
    return n_moves >= 9;
}

GameManager::GameManager(X_O_Board* bPtr, Player* playerPtr[2])
{
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run()
{
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over())
    {
        for (int i:{0,1})
        {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol()))
            {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner())
            {
                cout  << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw())
            {
                cout << "Draw!\n";
                return;
            }
        }
    }
}
RandomPlayer::RandomPlayer (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

void RandomPlayer::get_move (int& x, int& y)
{
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}

Player::Player(char symbol)
{
    this->symbol = symbol;
}

Player::Player (int order, char symbol)
{
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

void Player::get_move (int& x, int& y)
{
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

string Player::to_string()
{
    return "Player: " + name ;
}

char Player::get_symbol() const
{
    return symbol;
}

int main()
{
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        players[1] = new RandomPlayer ('o', 5);

    GameManager x_o_game (new X_O_Board(), players);
    x_o_game.run();
    system ("pause");
}