class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        vector<int> minSum(width, 0);
        for(int row = 0; row < height; row++) {
            for(int col = 0; col < width; col++) {
                if(row == 0 && col == 0) {
                    minSum[col] = grid[row][col];
                }
                else if(row == 0) {
                    minSum[col] = grid[row][col] + minSum[col - 1];
                }
                else if(col == 0) {
                    minSum[col] = grid[row][col] + minSum[col];
                }
                else {
                    minSum[col] = grid[row][col] + min(minSum[col], minSum[col - 1]);
                }
            }
        }
        return minSum[width - 1];
    }
};

class Solution {
private:
    const int INVALID = -1;
    vector<vector<int>> dp;
    int findMinPathSum(int row, int col, vector<vector<int>>& grid) {
        if(row < 0 || col < 0) return INT_MAX/2;
        if(dp[row][col] != INVALID) return dp[row][col];

        dp[row][col] = grid[row][col];
        int valueFromTop = findMinPathSum(row - 1, col, grid);
        int valueFromLeft = findMinPathSum(row, col - 1, grid);
        if(min(valueFromTop, valueFromLeft) != INT_MAX/2) {
            dp[row][col] += min(valueFromTop, valueFromLeft);
        }
        return dp[row][col];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        dp.assign(height, vector<int>(width, INVALID));
        return findMinPathSum(height - 1, width - 1, grid);
    }
};