#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ROWS 6
#define COLS 7
#define TURNS 21

class Game
{
public:
    // Two-dimensional vector for the board
    vector<vector<char>> board;
    char winner;

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

        winner = '-';
    }

    void printBoard()
    {

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
        // check horizontals
        for (int i = ROWS - 1; i >= 0; i--)
        {

            if (((board[i][0] == 'b') && (board[i][1] == 'b') && (board[i][2] == 'b') && (board[i][3] == 'b')) ||
                ((board[i][1] == 'b') && (board[i][2] == 'b') && (board[i][3] == 'b') && (board[i][4] == 'b')) ||
                ((board[i][2] == 'b') && (board[i][3] == 'b') && (board[i][4] == 'b') && (board[i][5] == 'b')) ||
                ((board[i][3] == 'b') && (board[i][4] == 'b') && (board[i][5] == 'b') && (board[i][6] == 'b')))
            {

                winner = 'b';
                return false;
            }

            else if (((board[i][0] == 'r') && (board[i][1] == 'r') && (board[i][2] == 'r') && (board[i][3] == 'r')) ||
                     ((board[i][1] == 'r') && (board[i][2] == 'r') && (board[i][3] == 'r') && (board[i][4] == 'r')) ||
                     ((board[i][2] == 'r') && (board[i][3] == 'r') && (board[i][4] == 'r') && (board[i][5] == 'r')) ||
                     ((board[i][3] == 'r') && (board[i][4] == 'r') && (board[i][5] == 'r') && (board[i][6] == 'r')))
            {

                winner = 'r';
                return false;
            }
        }

        // check verticals
        for (int i = 0; i < COLS; i++)
        {
            if (((board[0][i] == 'b') && (board[1][i] == 'b') && (board[2][i] == 'b') && (board[3][i] == 'b')) ||
                ((board[1][i] == 'b') && (board[2][i] == 'b') && (board[3][i] == 'b') && (board[4][i] == 'b')) ||
                ((board[2][i] == 'b') && (board[3][i] == 'b') && (board[4][i] == 'b') && (board[5][i] == 'b')))
            {

                winner = 'b';
                return false;
            }

            else if (((board[0][i] == 'r') && (board[1][i] == 'r') && (board[2][i] == 'r') && (board[3][i] == 'r')) ||
                     ((board[1][i] == 'r') && (board[2][i] == 'r') && (board[3][i] == 'r') && (board[4][i] == 'r')) ||
                     ((board[2][i] == 'r') && (board[3][i] == 'r') && (board[4][i] == 'r') && (board[5][i] == 'r')))
            {

                winner = 'r';
                return false;
            }
        }

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
    cout << "Game over. Winner: " << game.winner << "\n";
}