#include <iostream>
using namespace std;

struct TicTacToe {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int playerTurn = 1;
    char currentMarker = 'X';
};

void drawBoard(const char board[3][3]) {
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

bool placeMarker(char board[3][3], int slot, char marker) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O') return false;
    board[row][col] = marker;
    return true;
}

int checkWin(const char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

bool isDraw(const char board[3][3], int moves) {
    return moves == 9 && !checkWin(board);
}

int getValidSlot(int playerTurn, char currentMarker) {
    int slot;
    cout << "Player " << playerTurn << " (" << currentMarker << ") - Enter slot: ";
    while (!(cin >> slot) || slot < 1 || slot > 9) {
        cout << "Invalid input! Enter a number between 1 and 9: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return slot;
}

void switchPlayer(int& playerTurn, char& currentMarker) {
    playerTurn = (playerTurn == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
}

void startGame(TicTacToe& game) {
    int moves = 0;
    while (true) {
        drawBoard(game.board);
        int slot = getValidSlot(game.playerTurn, game.currentMarker);
        
        if (!placeMarker(game.board, slot, game.currentMarker)) {
            cout << "Slot already taken! Try again.\n";
            continue;
        }
        moves++;
        
        if (checkWin(game.board)) {
            drawBoard(game.board);
            cout << "Player " << game.playerTurn << " wins!\n";
            break;
        }
        
        if (isDraw(game.board, moves)) {
            drawBoard(game.board);
            cout << "It's a draw!\n";
            break;
        }
        
        switchPlayer(game.playerTurn, game.currentMarker);
    }
}

bool playAgain() {
    char choice;
    cout << "Play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    cout << "Welcome to Tic Tac Toe!\n";
    cout << "Player 1 is X, Player 2 is O\n";
    
    do {
        TicTacToe game;
        startGame(game);
    } while (playAgain());
    
    return 0;
}
