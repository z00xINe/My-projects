// File name: A3_Task2_S10_20220401
// Author(s): Youssef Amr
// ID(s): 20220401
// Section: 10
// Date: 14/12/2023

#include <bits/stdc++.h>

using namespace std;

class X_O_Board
{
private:
    static const int n_rows = 6, n_cols = 7;
    char board[6][7]{};
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
            j = 0;
    }
}

bool X_O_Board::update_board (int x, int y, char mark)
{
    if (!(x < 0 || x > 5 || y < 0 || y > 6) && (board[x][y] == 0))
    {
        if (board[x+1][y] != 0 || x == 5)
        {
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
        }
        else
        {
            for (int i = 5; i > x; --i)
            {
                if (board[i][y] == 0)
                {
                    board[i][y] = toupper(mark);
                    n_moves++;
                    return true;
                }
            }
        }
    }
    else
        return false;
}

void X_O_Board::display_board()
{
    for (int i: {0, 1, 2, 3, 4, 5})
    {
        cout << "\n| ";
        for (int j: {0, 1, 2, 3, 4, 5, 6})
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(2)<< board [i][j] << " |";
        }
        cout << "\n";
    }
    cout << endl;
}

bool X_O_Board::is_winner()
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

bool X_O_Board::is_draw()
{
    return (n_moves == 42 && !is_winner());
}

bool X_O_Board::game_is_over() const
{
    return n_moves >= 42;
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
        for (int i:{0, 1})
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
    cout << "\nPlease enter your move x and y (0 to 6) separated by spaces: ";
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
        players[1] = new RandomPlayer ('o', 6);

    GameManager x_o_game (new X_O_Board(), players);
    x_o_game.run();
    system ("pause");
}