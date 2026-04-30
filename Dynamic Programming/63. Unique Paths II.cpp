class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) { // T.C: O(N*M) S.C: O(M)
        int height = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        vector<int> ways(width, 0);
        ways[0] = 1;
        for(int row = 0; row < height; row++) {
            for(int col = 0; col < width; col++) {
                if(obstacleGrid[row][col] == 1) {
                    ways[col] = 0;
                    continue;
                }
                if(col > 0) {
                    ways[col] += ways[col - 1];
                }
            }
        }
        return ways[width - 1];
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) { // T.C: O(N*M) S.C: O(M)
        int height = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        vector<int> ways(width, 0);
        ways[0] = 1;
        for(int row = 0; row < height; row++) {
            for(int col = 0; col < width; col++) {
                if(obstacleGrid[row][col] == 1) {
                    ways[col] = 0;
                    continue;
                }
                if(col > 0) {
                    ways[col] += ways[col - 1];
                }
            }
        }
        return ways[width - 1];
    }
};