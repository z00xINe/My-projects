#include <bits/stdc++.h>
#define z00xINe ios_base::sync_with_stdio(false)

using namespace std;

class X_O_Board
{
protected:
    int n_rows, n_cols;
    char board[7][7]{};
    int  n_moves = 0;

public:
    explicit X_O_Board(char Game);
    bool update_board(int x, int y, char mark, char Game);
    void display_board(char Game);
    bool is_winner(char Game);
    void is_winner_game3();
    bool is_draw(char Game);
    bool game_not_over(char Game) const;
};

class Player
{
protected:
    string name;
    char symbol;

public:
    explicit Player (char symbol);
    explicit Player (int order);
    virtual void get_move(int& x, int& y, char Game);
    string to_string();
    char get_symbol() const;
};

class EasyPlayer: public Player
{
protected:
    int dimension{};

public:
    explicit EasyPlayer(int dimension);
    void get_move(int& x, int& y, char Game) override;
};

class GameManager
{
protected:
    X_O_Board* boardPtr;
    Player* players[2]{};

public:
    GameManager(X_O_Board* bPtr, Player* playerPtr[2]);
    void run(char Game);
};

X_O_Board::X_O_Board(char Game)
{
    if (Game == '1')
        n_rows = 3, n_cols = 5;

    else if (Game == '2')
        n_rows = 6, n_cols = 7;

    else if (Game == '3')
        n_rows = 5, n_cols = 5;

    else
        n_rows = n_cols = 3;

    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool X_O_Board::update_board (int x, int y, char mark, char Game)
{
    if (!(x < 0 || x > 2 || y < 0 || y > 4) && (board[x][y] == 0) && (Game == '1'))
    {
        if ((x==0 && y==2) || (x==1 && y==1) || (x==1 && y==2) || (x==1 && y==3) || (x==2))
        {
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
        }
            return false;
    }

    if (!(x < 0 || x > 5 || y < 0 || y > 6) && (board[x][y] == 0) && (board[x+1][y] != 0 || x == 5) && (Game == '2'))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }

    else if (Game == '3')
    {
        if (x < 0 || x > 4 || y < 0 || y > 4 || board[x][y] != 0)
            return true;

        else
        {
            board[x][y] = toupper(mark);
            n_moves++;
            return false;
        }
    }

    if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0) && (Game == '4'))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }

    return false;
}

void X_O_Board::display_board(char Game)
{
    if (Game == '1')
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
                else if ((i == 1 && j==2) || (i == 1 && j==3))
                {
                    cout << "(" << i << "," << j << ")" << setw(2) << board [i][j] << " |";
                }
                else if (i == 2 && j==0)
                {
                    cout <<" |"<< "(" << i << "," << j << ")" << setw(2) << board [i][j] << " |";
                }
                else if (i == 2)
                {
                    cout << "(" << i << "," << j << ")" << setw(2) << board [i][j] << " |";
                }
            }
            cout << "\n-----------------------------------------------";
        }
        cout << endl;
    }

    else if (Game == '2')
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

    else if (Game == '3')
    {
        for (int i : {0, 1, 2, 3, 4})
        {
            cout << "\n|";
            for (int j : {0, 1, 2, 3, 4})
            {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] << " |";
            }
            cout << "\n-----------------------------------------------";
        }
        cout << endl;
    }

    else
    {
        for (int i: {0, 1, 2})
        {
            cout << "\n| ";
            for (int j: {0, 1, 2})
            {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] << " |";
            }
            cout << "\n-----------------------------";
        }
        cout << endl;
    }
}

void X_O_Board::is_winner_game3()
{
    int win_x = 0, win_o = 0;
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
                board[i+2][i+2] == 'X')
                win_x++;

            // Rows wins for 'O'
            if (board[i][j] == 'X' &
                board[i][j+1] == 'X' &
                board[i][i+2] == 'X')
                win_x++;

            // Cols wins for 'O'
            if (board[i][j] == 'X' &
                board[i+1][j] == 'X' &
                board[i+2][i] == 'X')
                win_x++;

            // Diagonal for 'O'
            if (board[i][j] == 'O' &
                board[i+1][j+1] == 'O' &
                board[i+2][j+2] == 'O')
                win_o++;
        }
    }

    if (win_x > win_o)
        cout << "The result is " << win_x << " : " << win_o << "\nSo, player 1 wins!";

    else if (win_x < win_o)
        cout << "The result is " << win_x << " : " << win_o << "\nSo, player 2 wins!";

    else
        cout << "The result is " << win_x << " : " << win_o << "\nSo, the game is draw!";
}

bool X_O_Board::is_winner(char Game)
{
    if (Game == '1')
    {
        char row_win[5], col_win[3], diag_win[2];
        for (int i : {0, 1, 2})
        {
            if (i==1)
                row_win[i] = board[i][1] & board[i][2] & board[i][3];

            if (i==2)
                int j = 0;

            for(int j = 0,i=2;i<5;i++,j++)
            {
                row_win[i] = board[2][j] & board[2][j+1] & board[2][j+2];
            }
            col_win[i] = board[0][i] & board[1][i] & board[2][i];
        }
        diag_win[0] = board[0][2] & board[1][3] & board[2][4];
        diag_win[1] = board[0][2] & board[1][1] & board[2][0];

        for (int i:{0, 1, 2, 3, 4})
        {
            if ((row_win[i] && (row_win[i] == board[1][2])) || (row_win[i] && (row_win[i] == board[2][2])) ||
                (col_win[i] && (col_win[i] == board[0][i])) )
                return true;
        }
        if ((diag_win[0] && diag_win[0] == board[2][4]) ||
            (diag_win[1] && diag_win[1] == board[2][0]))
            return true;

        return false;
    }

    else if (Game == '2')
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

    else if (Game == '4')
    {
        char row_win[3], col_win[3], diag_win[2];
        for (int i:{0, 1, 2})
        {
            row_win[i] = board[i][0] & board[i][1] & board[i][2];
            col_win[i] = board[0][i] & board[1][i] & board[2][i];
        }
        diag_win[0] = board[0][0] & board[1][1] & board[2][2];
        diag_win[1] = board[2][0] & board[1][1] & board[0][2];

        for (int i:{0,1,2})
        {
            if ((row_win[i] && (row_win[i] == board[i][0])) || (col_win[i] && (col_win[i] == board[0][i])))
                return true;
        }
        if ((diag_win[0] && diag_win[0] == board[1][1]) || (diag_win[1] && diag_win[1] == board[1][1]))
            return true;

        return false;
    }
}

bool X_O_Board::is_draw(char Game)
{
    if (Game == '4' || Game == '1')
        return (n_moves == 9 && !is_winner(Game));

    else if (Game == '2')
        return (n_moves == 42 && !is_winner(Game));
}

bool X_O_Board::game_not_over(char Game) const
{
    if (Game == '1' || Game == '4')
        return n_moves < 9;

    else if (Game == '2')
        return n_moves < 42;

    else
        return n_moves < 25;
}

Player::Player(char symbol)
{
    this->symbol = symbol;
}

Player::Player (int order)
{
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name:";
    cin >> name;
    if (order == 1)
        this->symbol = 'x';
    else
        this->symbol = 'o';
}

void Player::get_move (int& x, int& y, char Game)
{
    cout << "\nPlease enter your move x and y separated by spaces:";
    cin >> x >> y;
}

char Player::get_symbol() const
{
    return symbol;
}

string Player::to_string()
{
    return "Player: " + name;
}

EasyPlayer::EasyPlayer(int dimension) : Player('o')
{
    this->dimension = dimension;
    cout << "My names is Random Computer Player" << endl;
}

void EasyPlayer::get_move(int& x, int& y, char Game)
{
    x = rand() % dimension;
    y = rand() % dimension;
}

GameManager::GameManager(X_O_Board* bPtr, Player* playerPtr[2])
{
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run(char Game)
{
    int x, y;
    boardPtr->display_board(Game);

    if (Game == '3')
    {
        while (boardPtr->game_not_over(Game))
        {
            for (int i: {0, 1})
            {
                players[i]->get_move(x, y, Game);

                while (boardPtr->update_board(x, y, players[i]->get_symbol(), Game) &&
                       boardPtr->game_not_over(Game))
                    players[i]->get_move(x, y, Game);

                boardPtr->display_board(Game);
            }
        }
        boardPtr->is_winner_game3();
    }
    else
    {
        while (boardPtr->game_not_over(Game))
        {
            for (int i:{0, 1})
            {
                players[i]->get_move(x, y, Game);
                while (!(boardPtr->update_board(x, y, players[i]->get_symbol(), Game)) &&
                       boardPtr->game_not_over(Game))
                {
                    players[i]->get_move(x, y, Game);
                }
                boardPtr->display_board(Game);
                if (boardPtr->is_winner(Game))
                {
                    cout  << players[i]->to_string() << " wins\n";
                    return;
                }
                if (boardPtr->is_draw(Game))
                {
                    cout << "Draw!\n";
                    return;
                }
            }
        }
    }
}

int main()
{
    z00xINe;

    cout << "Welcome to X-O Game. :)\n==================================\n\n";

    char choice, Game;
    Player* players[2];
    players[0] = new Player(1);

    cout << "Choose game that you want!\n1- Pyramic Tic-Tac-Toe.\n2- Four-in-a-row.\n3- 5 x 5 Tic Tac Toe.\n"
            "4- 3 x 3 Tic Tac Toe.\n"
            "Your choice >>";
    cin >> Game;

    cout << R"(If you want to play with computer, press '1' for "YES" or '0' for "NO":)";
    cin >> choice;

    if (choice == '0')
        players[1] = new Player(2);

    else if (choice == '1')
        players[1] = new EasyPlayer(6);

    GameManager x_o_game (new X_O_Board(Game), players);
    x_o_game.run(Game);

    return 0;
}