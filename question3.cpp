#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Game board
vector<vector<char>> board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

// Function to display the game board
void displayBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// Function to check if a player has won
bool checkWin(char player)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    char currentPlayer = 'X';
    int move;

    while (true)
    {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        // Update the game board
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(currentPlayer))
        {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check if the game is a draw
        if (checkDraw())
        {
            displayBoard();
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Ask if the players want to play again
    cout << "Do you want to play again? (y/n): ";
    char response;
    cin >> response;
    if (response == 'y')
    {
        // Reset the game board
        board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
        main();
    }

    return 0;
}