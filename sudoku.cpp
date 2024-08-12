[10:40 PM, 12/8/2024] Abhinav: #include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int SIZE = 9; // Size of Sudoku grid

// Function to print the Sudoku grid
void printGrid(const vector<vector<int>>& grid) {
    cout << "\nSudoku Grid:\n";
    for (int i = 0; i < SIZE; ++i) {
        if (i % 3 == 0 && i != 0) cout << "------+-------+------\n";
        for (int j = 0; j < SIZE; ++j) {
            if (j % 3 == 0 && j != 0) cout << "| ";
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << endl;
}

// Function to check if placing num in grid[row][col] is valid
bool isValid(const vector<vector<int>>& grid, int row, int col, int num) {
    // Check the row
    for (int x = 0; x < SIZE; ++x) {
        if (grid[row][x] == num) return false;
    }

    // Check the column
    for (int x = 0; x < SIZE; ++x) {
        if (grid[x][col] == num) return false;
    }

    // Check the 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + startRow][j + startCol] == num) return false;
        }
    }

    return true;
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(vector<vector<int>>& grid) {
    int row, col;
    bool empty = false;
    
    // Find an empty cell
    for (row = 0; row < SIZE; ++row) {
        for (col = 0; col < SIZE; ++col) {
            if (grid[row][col] == 0) {
                empty = true;
                break;
            }
        }
        if (empty) break;
    }

    // If there is no empty cell, the Sudoku is solved
    if (!empty) return true;

    // Try placing digits 1-9
    for (int num = 1; num <= 9; ++num) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            
            if (solveSudoku(grid)) return true;

            // Reset if placing num doesn't lead to a solution
            grid[row][col] = 0;
        }
    }
    
    return false;
}

int main() {
    vector<vector<int>> grid(SIZE, vector<int>(SIZE));

    cout << "Welcome to the Sudoku Solver!\n";
    cout << "Please enter the Sudoku puzzle (use 0 for empty cells):\n";

    // Input the Sudoku puzzle
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            while (true) {
                cout << "Enter value for cell [" << i + 1 << "][" << j + 1 << "] (0-9): ";
                int value;
                cin >> value;
                
                // Input validation
                if (cin.fail() || value < 0 || value > 9) {
                    cin.clear(); // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input. Please enter a number between 0 and 9.\n";
                } else {
                    grid[i][j] = value;
                    break;
                }
            }
        }
    }

    cout << "\nInitial Sudoku Grid:\n";
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku puzzle.\n";
    }

    return 0;
}
[10:57 PM, 12/8/2024] Abhinav: .
