class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int minTotal = triangle.size() == 1 ? triangle[0][0] : INT_MAX;
        for(int row = 1; row < triangle.size(); row++) {
            for(int col = 0; col < triangle[row].size(); col++) {
                if(col == 0) {
                    triangle[row][col] += triangle[row - 1][col];
                }
                else if(col + 1 == triangle[row].size()) {
                    triangle[row][col] += triangle[row - 1][col - 1];
                }
                else {
                    triangle[row][col] = triangle[row][col] 
                        + min(triangle[row - 1][col], triangle[row - 1][col - 1]);
                }

                if(row + 1 == triangle.size()) {
                    minTotal = min(minTotal, triangle[row][col]);
                }
            }
        }
        return minTotal;
    }
};

class Solution {
private:
    const int INVALID = -1;
    vector<vector<int>> dp;
    vector<vector<bool>> isVisited;
    int findMinTotal(int row, int col, vector<vector<int>>& triangle) {
        if(row + 1 == triangle.size()) {
            return triangle[row][col];
        }
        if(col >= triangle[row].size()) {
            return INT_MAX/2;
        }
        if(isVisited[row][col]) {
            return dp[row][col];
        }
        // cout << row << " " << col << '\n';
        dp[row][col] = triangle[row][col] 
                        + min(findMinTotal(row + 1, col, triangle), 
                            findMinTotal(row + 1, col + 1, triangle));
        isVisited[row][col] = true;
        return dp[row][col];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        int width = triangle[height - 1].size();
        isVisited.assign(triangle.size(), vector<bool>(width, false));
        dp.assign(triangle.size(), vector<int>(width, 0));
        return findMinTotal(0, 0, triangle);
    }
};