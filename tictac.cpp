#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int playerTurn = 1;
char currentMarker;

void drawBoard() {
    system("clear"); // Use "cls" for Windows
    cout << "\n Tic Tac Toe\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O') return false;
    board[row][col] = currentMarker;
    return true;
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1; // Row win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1; // Column win
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1; // Diagonal win
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1; // Other diagonal win
    return 0;
}

void startGame() {
    int slot;
    int moves = 0;
    currentMarker = (playerTurn == 1) ? 'X' : 'O';
    
    while (true) {
        drawBoard();
        cout << "Player " << playerTurn << " (" << currentMarker << ") - Enter slot: ";
        cin >> slot;
        
        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }
        moves++;
        
        if (checkWin()) {
            drawBoard();
            cout << "Player " << playerTurn << " wins!\n";
            break;
        }
        
        if (moves == 9) {
            drawBoard();
            cout << "It's a draw!\n";
            break;
        }
        
        playerTurn = (playerTurn == 1) ? 2 : 1;
        currentMarker = (currentMarker == 'X') ? 'O' : 'X';
    }
}

int main() {
    cout << "Welcome to Tic Tac Toe!\n";
    cout << "Player 1 is X, Player 2 is O\n";
    startGame();
    return 0;
}
