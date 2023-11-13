#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    cout << "  1   2   3" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "  ---+---+---" << endl;
    }
    cout << endl;
}

// Function to check if the current player has won
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';
    bool gameOver = false;
    char playAgain;

    cout << "\t\t\t**************Welcome to Tic-Tac-Toe!**************" << endl;

    do
    {
        while (!gameOver) {
            displayBoard(board);
            int row, col;

            // Get player input
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            // Check for valid input
            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            // Update the board
            board[row - 1][col - 1] = currentPlayer;

            // Check for a win
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
                gameOver = true;
            } else if (checkDraw(board)) {
                // Check for a draw
                displayBoard(board);
                cout << "It's a draw! The game is over." << endl;
                gameOver = true;
            } else {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

         // Ask if the player wants to play again
        cout << "Do you want to play another game? (y/n): ";
        cin >> playAgain;

        if (playAgain == 'y' || playAgain == 'Y') {
            // Reset the game state
            board[0][0] = board[0][1] = board[0][2] = ' ';
            board[1][0] = board[1][1] = board[1][2] = ' ';
            board[2][0] = board[2][1] = board[2][2] = ' ';
            currentPlayer = 'X';
            gameOver = false;
        } else {
            cout << "Thank you for playing Tic-Tac-Toe!" << endl;
        }

    }while (playAgain == 'y' || playAgain == 'Y');


    return 0;
}
