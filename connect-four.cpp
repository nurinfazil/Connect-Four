#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

#define ROWS 6
#define COLS 7
#define TURNS 21

// Game class tracks all data for the ongoing game
class Game
{
public:
    // Two-dimensional vector for the board
    vector<vector<char>> board;
    char winner;
    int P1NumTurns = 0;
    int P2NumTurns = 0;

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
        P1NumTurns = TURNS;
        P2NumTurns = TURNS;
    }

    // Prints the Connect-4 Board.
    void printBoard()
    {
        cout << "\n";

        for (int i = 0; i < 7; i++)
        {
            cout << "   " << i;
        }

        cout << "\n";

        for (int i = 0; i < ROWS; i++)
        {
            cout << " | ";
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

    // Checks for Connect Four and also checks if there is a tie
    bool isPlaying()
    {
        // check horizontals for win

        for (int i = ROWS - 1; i >= 0; i--)
        {
            for (int j = 0; j < (COLS - 3); j++)
            {
                if ((board[i][j] == 'b') && (board[i][j + 1] == 'b') && (board[i][j + 2] == 'b') && (board[i][j + 3] == 'b'))
                {
                    winner = 'b';
                    return false;
                }
                else if ((board[i][j] == 'r') && (board[i][j + 1] == 'r') && (board[i][j + 2] == 'r') && (board[i][j + 3] == 'r'))
                {
                    winner = 'r';
                    return false;
                }
            }
        }

        // check verticals for win

        for (int i = 0; i < COLS; i++)
        {
            for (int j = 0; j < (ROWS - 3); j++)
            {
                if ((board[j][i] == 'b') && (board[j + 1][i] == 'b') && (board[j + 2][i] == 'b') && (board[j + 3][i] == 'b'))
                {
                    winner = 'b';
                    return false;
                }
                else if ((board[j][i] == 'r') && (board[j + 1][i] == 'r') && (board[j + 2][i] == 'r') && (board[j + 3][i] == 'r'))
                {
                    winner = 'r';
                    return false;
                }
            }
        }

        // check back-slash (\) diagonals for win

        for (int i = 2; i >= 0; i--)
        {
            char check1 = backSlashDiagonalCheckerMaxRow(i, 0);
            if (check1 == 'b')
            {
                winner = 'b';
                return false;
            }
            else if (check1 == 'r')
            {
                winner = 'r';
                return false;
            }
        }

        for (int i = 1; i <= 3; i++)
        {
            char check2 = backSlashDiagonalCheckerMaxCol(0, i);
            if (check2 == 'b')
            {
                winner = 'b';
                return false;
            }
            else if (check2 == 'r')
            {
                winner = 'r';
                return false;
            }
        }

        // check forward-slash (/) diagonals

        for (int i = 3; i <= 5; i++)
        {
            char check3 = forwardSlashDiagonalCheckerMinRow(i, 0);
            if (check3 == 'b')
            {
                winner = 'b';
                return false;
            }
            else if (check3 == 'r')
            {
                winner = 'r';
                return false;
            }
        }

        for (int i = 1; i <= 3; i++)
        {
            char check4 = forwardSlashDiagonalCheckerMaxRow(5, i);
            if (check4 == 'b')
            {
                winner = 'b';
                return false;
            }
            else if (check4 == 'r')
            {
                winner = 'r';
                return false;
            }
        }

        // Declare a tie if both players are out of turns

        if ((P1NumTurns <= 0) && (P2NumTurns <= 0))
        {
            winner = '=';
            return false;
        }

        return true;
    }

    // Checks if there is a back-slash diagonal from [2][0], [1][0], [0][0]
    char backSlashDiagonalCheckerMaxRow(int currRow, int currCol)
    {
        while ((currRow + 3) <= (ROWS - 1))
        {

            if ((board[currRow][currCol] == 'b') && (board[currRow + 1][currCol + 1] == 'b') &&
                (board[currRow + 2][currCol + 2] == 'b') && (board[currRow + 3][currCol + 3] == 'b'))
            {

                return 'b';
            }
            else if ((board[currRow][currCol] == 'r') && (board[currRow + 1][currCol + 1] == 'r') &&
                     (board[currRow + 2][currCol + 2] == 'r') && (board[currRow + 3][currCol + 3] == 'r'))
            {

                return 'r';
            }

            currRow++;
            currCol++;
        }
        return '-';
    }

    // Checks if there is a back-slash diagonal starting from [0][1], [0][2], [0][3]
    char backSlashDiagonalCheckerMaxCol(int currRow, int currCol)
    {
        while ((currCol + 3) <= (COLS - 1))
        {

            if ((board[currRow][currCol] == 'b') && (board[currRow + 1][currCol + 1] == 'b') &&
                (board[currRow + 2][currCol + 2] == 'b') && (board[currRow + 3][currCol + 3] == 'b'))
            {

                return 'b';
            }
            else if ((board[currRow][currCol] == 'r') && (board[currRow + 1][currCol + 1] == 'r') &&
                     (board[currRow + 2][currCol + 2] == 'r') && (board[currRow + 3][currCol + 3] == 'r'))
            {

                return 'r';
            }

            currRow++;
            currCol++;
        }
        return '-';
    }

    // Checks if there is a forward-slash diagonal starting from [3][0], [4][0], [5][0]
    char forwardSlashDiagonalCheckerMinRow(int currRow, int currCol)
    {
        while ((currRow - 3) >= 0)
        {

            if ((board[currRow][currCol] == 'b') && (board[currRow - 1][currCol + 1] == 'b') &&
                (board[currRow - 2][currCol + 2] == 'b') && (board[currRow - 3][currCol + 3] == 'b'))
            {

                return 'b';
            }
            else if ((board[currRow][currCol] == 'r') && (board[currRow - 1][currCol + 1] == 'r') &&
                     (board[currRow - 2][currCol + 2] == 'r') && (board[currRow - 3][currCol + 3] == 'r'))
            {

                return 'r';
            }

            currRow--;
            currCol++;
        }
        return '-';
    }

    // Checks if there is a forward-slash diagonal starting from [5][1], [5][2], [5][3]
    char forwardSlashDiagonalCheckerMaxRow(int currRow, int currCol)
    {
        while ((currCol + 3) <= (COLS - 1))
        {

            if ((board[currRow][currCol] == 'b') && (board[currRow - 1][currCol + 1] == 'b') &&
                (board[currRow - 2][currCol + 2] == 'b') && (board[currRow - 3][currCol + 3] == 'b'))
            {

                return 'b';
            }
            else if ((board[currRow][currCol] == 'r') && (board[currRow - 1][currCol + 1] == 'r') &&
                     (board[currRow - 2][currCol + 2] == 'r') && (board[currRow - 3][currCol + 3] == 'r'))
            {

                return 'r';
            }

            currRow--;
            currCol++;
        }
        return '-';
    }

    // Puts a player's piece into the specified column. If the column is full, returns a message saying it is full.
    void pickColumn(char player, int column)
    {
        if (player == 'b')
        {
            P1NumTurns--;
        }

        else if (player == 'r')
        {
            P2NumTurns--;
        }

        if (column > 6 || column < 0)
        {
            cout << "Invalid move. Pick a column between 0 and 6 next time.\n";
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

        cout << "Can't make move. Column is full. Choose another column next time.\n";
    }

    // Returns game winner (either 'b' or 'r'). If no winner, returns '-'. If it's a tie, returns '='.
    char getWinner()
    {
        return winner;
    }
};

int main()
{
    Game game;
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
            while (!cin.good())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Try again\n";
                cout << "Player 1's move: ";
                cin >> move;
            }
            game.pickColumn(activePlayer, move);
            activePlayer = P2;
        }
        else
        {
            cout << "Player 2's move: ";
            int move;
            cin >> move;
            while (!cin.good())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Try again\n";
                cout << "Player 2's move: ";
                cin >> move;
            }
            game.pickColumn(activePlayer, move);
            activePlayer = P1;
        }
        game.printBoard();
    }
    cout << "Winner is: " << game.getWinner() << "\n";
}