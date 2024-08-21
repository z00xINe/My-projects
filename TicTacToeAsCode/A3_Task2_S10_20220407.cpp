// File name: A3_Task2_S10_20220407
// Author(s): Youssef Mohamed
// ID(s): 20220407
// Section: 10
// Date: 12/12/2023

#include <bits/stdc++.h>
#define z00xINe ios_base::sync_with_stdio(false)

using namespace std;

class X_O_Board
{
protected:
    static const int n_rows = 5, n_cols = 5;
    char board[5][5]{};
    int  n_moves = 0;

public:
    X_O_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    void is_winner();
    bool game_not_over() const;
    friend class SmartPlayer;
};

class Player
{
protected:
    string name;
    char symbol;

public:
    explicit Player (char symbol);
    explicit Player (int order);
    virtual void get_move(int& x, int& y);
    string to_string();
    char get_symbol() const;
};

class EasyPlayer: public Player
{
protected:
    int dimension{};

public:
    explicit EasyPlayer(int dimension);
    void get_move(int& x, int& y) override;
};

class SmartPlayer: public Player
{
protected:
    int dimension;
    X_O_Board* boardPtr{};

public:
    explicit SmartPlayer(int dimension);
    void get_move(int& x, int& y) override;
    int minimax(char board[5][5], int depth, bool isMaximizing);
};

class GameManager
{
protected:
    X_O_Board* boardPtr;
    Player* players[2]{};

public:
    GameManager(X_O_Board* bPtr, Player* playerPtr[2]);
    void run();
};

X_O_Board::X_O_Board()
{
    for (auto & i : board)
    {
        for (char & j : i)
            j = 0;
    }
}

bool X_O_Board::update_board (int x, int y, char mark)
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

void X_O_Board::display_board()
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

void X_O_Board::is_winner()
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

    if (win_x > win_o)
        cout << "The result is " << win_x << " : " << win_o << "\nSo, player 1 wins!";

    else if (win_x < win_o)
        cout << "The result is " << win_x << " : " << win_o << "\nSo, player 2 wins!";

    else
        cout << "The result is " << win_x << " : " << win_o << "\nSo, the game is draw!";
}

bool X_O_Board::game_not_over() const
{
    return n_moves <= 24;
}

EasyPlayer::EasyPlayer(int dimension) : Player('o')
{
    this->dimension = dimension;
    cout << "My names is Random Computer Player" << endl;
}

void EasyPlayer::get_move(int& x, int& y)
{
    x = rand() % dimension;
    y = rand() % dimension;
}

SmartPlayer::SmartPlayer(int dimension) : Player('o')
{
    this->dimension = dimension;
    cout << "My names is Smart Computer Player!" << endl;
}

void SmartPlayer::get_move(int& x, int& y)
{
    char tempBoard[5][5];
    memcpy(tempBoard, boardPtr->board, sizeof(tempBoard));

    int bestScore = INT_MIN;
    int moveScore;
    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < dimension; ++j)
        {
            if (tempBoard[i][j] == 0)
            {
                tempBoard[i][j] = symbol;
                moveScore = minimax(tempBoard, 0, false);  // Evaluate the move
                tempBoard[i][j] = 0;

                if (moveScore > bestScore)
                {
                    bestScore = moveScore;
                    x = i;
                    y = j;
                }
            }
        }
    }
}

int SmartPlayer::minimax(char board[5][5], int depth, bool isMaximizing)
{
    int bestScore = isMaximizing ? INT_MIN : INT_MAX;
    int moveScore;

    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < dimension; ++j)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = isMaximizing ? symbol : 'X';
                moveScore = minimax(board, depth + 1, !isMaximizing);
                board[i][j] = 0;

                if ((isMaximizing && moveScore > bestScore) || (!isMaximizing && moveScore < bestScore))
                    bestScore = moveScore;
            }
        }
    }

    return bestScore;
}

Player::Player(char symbol)
{
    this->symbol = symbol;
}

Player::Player (int order)
{
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    if (order == 1)
        this->symbol = 'X';
    else
        this->symbol = 'O';
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

GameManager::GameManager(X_O_Board *bPtr, Player **playerPtr)
{
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run()
{
    int x, y;

    boardPtr->display_board();

    while (boardPtr->game_not_over())
    {
        for (int i : {0, 1})
        {
            players[i]->get_move(x, y);
            while ((boardPtr->update_board(x, y, players[i]->get_symbol())) && boardPtr->game_not_over())
                players[i]->get_move(x, y);

            boardPtr->display_board();
        }
    }
    boardPtr->is_winner();
}

int main()
{
    z00xINe;

    cout << "Welcome to FCAI X-O Game. :)\n==================================\n\n";

    char choice;
    Player* players[2];
    players[0] = new Player(1);

    cout << R"(If you want to play with computer, press '1' for "YES" or '0' for "NO":)";
    cin >> choice;

    if (choice == '0')
        players[1] = new Player(2);

    else if (choice == '1')
    {
        cout << "Choose level of computer player:\n1- Easy.\n2- Hard.\nYour choice >>";
        cin >> choice;
        players[1] = new EasyPlayer(5);
    }

    GameManager x_o_game (new X_O_Board(), players);
    x_o_game.run();
    system ("pause");

    return 0;
}