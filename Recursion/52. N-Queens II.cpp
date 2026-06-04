class Solution {
private:
    int validQueenPlacements;
    vector<vector<int>> queenPlacedTillNow;
    bool isTheCellAvailableForQueenPlacement(int row, int col) {
        for(auto& queenCell: queenPlacedTillNow) {
            int queenRow = queenCell[0], queenCol = queenCell[1];
            if(queenRow == row || queenCol == col || abs(queenRow - row) == abs(queenCol - col)) {
                return false;
            }
        }
        return true;
    }

    void backtrack(int queenPlaced, int currentRow, int n) {
        if(queenPlaced < currentRow) {
            return;
        }
        if(queenPlaced == n) {
            validQueenPlacements++;
        }
        if(currentRow == n) {
            return;
        }

        for(int col = 0; col < n; col++) {
            if(isTheCellAvailableForQueenPlacement(currentRow, col)) {
                queenPlacedTillNow.push_back({currentRow, col});
                backtrack(queenPlaced + 1, currentRow + 1, n);
                queenPlacedTillNow.pop_back();
            }
        }
    }

public:
    int totalNQueens(int n) {
        validQueenPlacements = 0;
        backtrack(0, 0, n);
        return validQueenPlacements;
    }
};