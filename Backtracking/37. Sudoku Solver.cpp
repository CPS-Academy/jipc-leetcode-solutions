class Solution {
private:
    const int SUDOKU_SIZE = 9;
    const int SUB_GRID_SIZE = 3;
    vector<vector<int>> grid = vector<vector<int>>(SUDOKU_SIZE, vector<int>(SUDOKU_SIZE, 0));

    bool isValid(int row, int col, int val) {
        for(int i = 0; i < SUDOKU_SIZE; i++) {
            if(grid[row][i] == val || grid[i][col] == val) {
                return false;
            }
        }
        int subGridInitialRow = SUB_GRID_SIZE * (row/SUB_GRID_SIZE);
        int subGridInitialCol = SUB_GRID_SIZE * (col/SUB_GRID_SIZE);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(grid[i +  subGridInitialRow][j +  subGridInitialCol] == val) {
                    return false;
                }
            }
        }
        return true;
    }

    bool findBestCandidate(int& r, int& c) {        // true -> found at-least a candidate
        int minCandidates = 10;                     // false -> no candidate found
        for(int row = 0; row < SUDOKU_SIZE; row++) {
            for(int col = 0; col < SUDOKU_SIZE; col++) {
                if(grid[row][col] > 0) {
                    continue;
                }
                int candidates = 0;
                for(int candidateValue = 1; candidateValue < SUDOKU_SIZE; candidateValue++) {
                    if(isValid(row, col, candidateValue)) {
                        candidates++;
                    }
                }
                if(candidates < minCandidates) {
                    minCandidates = candidates;
                    r = row, c = col;
                }
            }
        }
        return minCandidates < 10;
    }
    
    bool backtrack() {              // true -> if a valid sudoku is possible from the current combo.
        int row, col;               // false-> no valid sudoku possible from the current combo. 
        if(!findBestCandidate(row, col)) {
            return true;
        }
        for(int value = 1; value <= SUDOKU_SIZE; value++) {
            if(!isValid(row, col, value)) {
                continue;
            }
            grid[row][col] = value;
            if(backtrack()) {
                return true;
            }
        }
        grid[row][col] = 0;
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < SUDOKU_SIZE; row++) {
            for(int col = 0; col < SUDOKU_SIZE; col++) {
                if(board[row][col] != '.') {
                    grid[row][col] = board[row][col] - '0';
                }
            }
        }
        backtrack();
        for(int row = 0; row < SUDOKU_SIZE; row++) {
            for(int col = 0; col < SUDOKU_SIZE; col++) {
                board[row][col] = grid[row][col] + '0';
            }
        }
    }
};