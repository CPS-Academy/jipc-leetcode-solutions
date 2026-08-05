class Solution {
private:
    vector<vector<string>> uniqueValidQueenPlacements;
    vector<vector<int>> placedQueenTillNow;
    void placeQueensOnChessboard(int n) {
        string chessboardRow(n, '.');
        vector<string> chessBoard = vector<string>(n, chessboardRow);
        for(int i = 0; i < placedQueenTillNow.size(); i++) {
            int row = placedQueenTillNow[i][0];
            int col = placedQueenTillNow[i][1];
            chessBoard[row][col] = 'Q';
        }
        uniqueValidQueenPlacements.push_back(chessBoard);
    }
    bool isValidPosition(int row, int col) {
        for(int i = 0; i < placedQueenTillNow.size(); i++) {
            int placedQueenRow = placedQueenTillNow[i][0];
            int placedQueenCol = placedQueenTillNow[i][1];
            if(row == placedQueenRow || col == placedQueenCol || abs(row - placedQueenRow) == abs(col - placedQueenCol)) {
                return false;
            }
        }
        return true;
    }
    void backtrack(int queenPlaced, int currentRow, int n) {
        if(queenPlaced == n && currentRow == n) { // a valid queen placement
            placeQueensOnChessboard(n);
            return;
        }
        if(currentRow == n) {
            return;
        }
        for(int col = 0; col < n; col++) {
            if(isValidPosition(currentRow, col)) {
                placedQueenTillNow.push_back({currentRow, col});
                backtrack(queenPlaced + 1, currentRow + 1, n);
                placedQueenTillNow.pop_back();
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        backtrack(0, 0, n);
        return uniqueValidQueenPlacements;
    }
};