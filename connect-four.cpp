#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ROWS 6
#define COLS 7

class Game
{
public:
    // Two-dimensional vector for the board
    vector<vector<char>> board;

    // Constructor
    Game()
    {
        // Initialize the board with 6 rows and 7 columns
        for (int i = 0; i < ROWS; i++)
        {
            vector<char> v;
            for (int j = 0; j < COLS; j++)
            {
                v.push_back('-');
            }

            board.push_back(v);
        }
    }

    void printBoard()
    {
        // for (int i = 0; i < ROWS; i++)
        // {
        //     for (int j = 0; j < COLS; j++)
        //     {
        //         cout << "board"
        //              << "[" << i << "][" << j << "]: " << board[i][j] << "\n";
        //     }
        // }

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                cout << board[i][j] << " | ";
                if (j == 6)
                {
                    cout << "\n";
                }
            }
        }
        cout << "\n";
    }

    bool isPlaying()
    {
        return true;
    }

    void pickColumn(char player, int column)
    {
        if (column > 7 || column < 0)
        {
            cout << "Invalid move. Pick a column between 0 and 6.\n";
            return;
        }

        for (int i = 5; i >= 0; i--)
        {
            if (board[i][column] == '-')
            {
                board[i][column] = player;
                return;
            }
            else if (board[i][column] != '-')
            {
                continue;
            }
        }

        cout << "Can't make move. Column is full.\n";
    }

    char getWinner()
    {
        char winner = 'b';
        return winner;
    }
};

int main()
{
    Game game;
    //game.printBoard();
    cout << "Beginning the game!\n";

    char P1 = 'b';
    char P2 = 'r';

    char activePlayer = P1;
    game.printBoard();

    while (game.isPlaying())
    {
        if (activePlayer == P1)
        {
            cout << "Player 1's move: ";
            int move;
            cin >> move;
            game.pickColumn(activePlayer, move);
            game.printBoard();
            activePlayer = P2;
        }
        else
        {
            cout << "Player 2's move: ";
            int move;
            cin >> move;
            game.pickColumn(activePlayer, move);
            game.printBoard();
            activePlayer = P1;
        }
    }
}
