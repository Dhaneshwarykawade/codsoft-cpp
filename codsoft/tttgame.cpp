#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function prototypes
void initializeBoard(vector<vector<char>> &board);
void displayBoard(const vector<vector<char>> &board);
bool makeMove(vector<vector<char>> &board, char currentPlayer, int row, int col);
bool checkWin(const vector<vector<char>> &board, char currentPlayer);
bool checkDraw(const vector<vector<char>> &board);
void switchPlayer(char &currentPlayer);
bool playAgain();
void displayTasks(const vector<string> &tasks, const vector<bool> &status);
void addTask(vector<string> &tasks, vector<bool> &status, const string &newTask);
void markTaskCompleted(vector<bool> &status, int taskIndex);
void removeTask(vector<string> &tasks, vector<bool> &status, int taskIndex);

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    vector<string> tasks;
    vector<bool> taskStatus;

    while (true) {
        // Display Tic-Tac-Toe board
        displayBoard(board);

        // Player Input
        int row, col;
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (1-3): ";
        cin >> row >> col;

        // Validate the input
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Update Board
        if (!makeMove(board, currentPlayer, row - 1, col - 1)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Check for Win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check for Draw
        if (checkDraw(board)) {
            displayBoard(board);
            cout << "The game is a draw!\n";
            break;
        }

        // Switch Players
        switchPlayer(currentPlayer);
    }

    // Ask if the players want to play again
    if (playAgain()) {
        initializeBoard(board);
        main(); // Start a new game
    } else {
        cout << "Thanks for playing!\n";
    }

    return 0;
}

// Function definitions

void initializeBoard(vector<vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char>> &board) {
    cout << "Game Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------\n";
    }
    cout << endl;
}

bool makeMove(vector<vector<char>> &board, char currentPlayer, int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        return false;
    }
}

bool checkWin(const vector<vector<char>> &board, char currentPlayer) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

bool checkDraw(const vector<vector<char>> &board) {
    // Check if the board is full
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

void displayTasks(const vector<string> &tasks, const vector<bool> &status) {
    cout << "\nTask List:\n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << " - " << (status[i] ? "Completed" : "Pending") << endl;
    }
    cout << endl;
}

void addTask(vector<string> &tasks, vector<bool> &status, const string &newTask) {
    tasks.push_back(newTask);
    status.push_back(false);
    cout << "Task added successfully.\n";
}

void markTaskCompleted(vector<bool> &status, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < status.size()) {
        status[taskIndex] = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

void removeTask(vector<string> &tasks, vector<bool> &status, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex);
        status.erase(status.begin() + taskIndex);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}
