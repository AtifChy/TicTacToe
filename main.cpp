#include <iostream>
#include <windows.h>

bool gameOver;
char board[3][3];

void setup() {
    gameOver = false;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = ' ';
        }
    }
}

void draw() {
    system("cls");

    std::cout << "\n";
    for (int row = 0; row < 3; row++) {
        std::cout << " ";
        for (int col = 0; col < 3; col++) {
            std::cout << board[row][col];
            if (col < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (row < 2) std::cout << "-----------\n";
    }
    std::cout << "\n";
}

void input() {
    int row, col;
    std::cout << "Enter row and column: ";
    std::cin >> row >> col;

    if (board[row][col] != ' ') {
        std::cout << "Invalid move. Try again!\n";
        input();
        return;
    }

    board[row][col] = 'X';
}

bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

void logic() {
    if (checkWin('X')) {
        draw();
        std::cout << "You win!\n";
        gameOver = true;
        return;
    }

    // Basic AI
    int emptyCells[9];
    int count = 0;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                emptyCells[count++] = row * 3 + col;
            }
        }
    }

    int move = -1;
    for (int i = 0; i < count; i++) {
        int row = emptyCells[i] / 3;
        int col = emptyCells[i] % 3;
        board[row][col] = 'O';
        if (checkWin('O')) {
            move = i;
            break;
        }
        board[row][col] = ' ';
    }

    if (move == -1) {
        for (int i = 0; i < count; i++) {
            int row = emptyCells[i] / 3;
            int col = emptyCells[i] % 3;
            board[row][col] = 'X';
            if (checkWin('X')) {
                move = i;
                break;
            }
            board[row][col] = ' ';
        }
    }

    if (count > 0) {
        if (move == -1) move = rand() % count;
        int randomRow = emptyCells[move] / 3;
        int randomCol = emptyCells[move] % 3;
        board[randomRow][randomCol] = 'O';
    }

    if (checkWin('O')) {
        draw();
        std::cout << "You lose!\n";
        gameOver = true;
    } else if (count == 0) {
        draw();
        std::cout << "Draw!\n";
        gameOver = true;
    }
}

int main(int, char**) {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(30);
    }
    return 0;
}
