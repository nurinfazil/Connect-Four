#include <iostream>
#include <vector>
#include <string>

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
    int P1NumTurns = TURNS;
    int P2NumTurns = TURNS;

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

    // Prints the Connect-4 Board.
    void printBoard()
    {

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

        if ((P1NumTurns <= 0) && (P2NumTurns <= 0))
        {
            winner = '=';
            return false;
        }

        // check horizontals for win
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

        // check verticals for win
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

        // check back-slash (\) diagonals for win

        // Diagonally from [2][0]
        char check1 = backSlashDiagonalCheckerMaxRow(2, 0);
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

        // Diagonally from [1][0]
        char check2 = backSlashDiagonalCheckerMaxRow(1, 0);
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

        // Diagonally from [0][0]
        char check3 = backSlashDiagonalCheckerMaxRow(0, 0);
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

        // Diagonally from [0][1]
        char check4 = backSlashDiagonalCheckerMaxCol(0, 1);
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

        // Diagonally from [0][2]
        char check5 = backSlashDiagonalCheckerMaxCol(0, 2);
        if (check5 == 'b')
        {
            winner = 'b';
            return false;
        }
        else if (check5 == 'r')
        {
            winner = 'r';
            return false;
        }

        // Diagonally from [0][3]
        char check6 = backSlashDiagonalCheckerMaxCol(0, 3);
        if (check6 == 'b')
        {
            winner = 'b';
            return false;
        }
        else if (check6 == 'r')
        {
            winner = 'r';
            return false;
        }

        // check forward-slash (/) diagonals

        // Diagonally from [3][0]
        char check7 = forwardSlashDiagonalCheckerMinRow(3, 0);
        if (check7 == 'b')
        {
            winner = 'b';
            return false;
        }
        else if (check7 == 'r')
        {
            winner = 'r';
            return false;
        }

        // Diagonally from [4][0]
        char check8 = forwardSlashDiagonalCheckerMinRow(4, 0);
        if (check8 == 'b')
        {
            winner = 'b';
            return false;
        }
        else if (check8 == 'r')
        {
            winner = 'r';
            return false;
        }

        // Diagonally from [5][0]
        char check9 = forwardSlashDiagonalCheckerMinRow(5, 0);
        if (check9 == 'b')
        {
            winner = 'b';
            return false;
        }
        else if (check9 == 'r')
        {
            winner = 'r';
            return false;
        }

        // Diagonally from [5][1]
        char check10 = forwardSlashDiagonalCheckerMaxRow(5, 1);
        if (check10 == 'b')
        {
            winner = 'b';
            return false;
        }
        else if (check10 == 'r')
        {
            winner = 'r';
            return false;
        }

        // Diagonally from [5][2]
        char check11 = forwardSlashDiagonalCheckerMaxRow(5, 2);
        if (check11 == 'b')
        {
            winner = 'b';
            return false;
        }
        else if (check11 == 'r')
        {
            winner = 'r';
            return false;
        }

        // Diagonally from [5][3]
        char check12 = forwardSlashDiagonalCheckerMaxRow(5, 3);
        if (check12 == 'b')
        {
            winner = 'b';
            return false;
        }
        else if (check12 == 'r')
        {
            winner = 'r';
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

    // Puts a player's piece into the specified column
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

        if (column > 7 || column < 0)
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
            game.pickColumn(activePlayer, move);
            activePlayer = P2;
        }
        else
        {
            cout << "Player 2's move: ";
            int move;
            cin >> move;
            game.pickColumn(activePlayer, move);
            activePlayer = P1;
        }
        game.printBoard();
    }
    cout << "Winner is: " << game.getWinner() << "\n";
}