class Solution {
private:
    vector<vector<int>> maxSquare;
    vector<vector<int>> rowWiseCount;
    vector<vector<int>> colWiseCount;

    void populateRowAndColWiseOneCount(int height, int weidth, vector<vector<char>>& matrix) {
        rowWiseCount.assign(height, vector<int>(weidth, 0));
        colWiseCount.assign(height, vector<int>(weidth, 0));
        maxSquare.assign(height, vector<int>(weidth, 0));

        for(int row = 0; row < height; row++) {
            for(int col = 0; col < weidth; col++) {
                if(matrix[row][col] == '1') {
                    rowWiseCount[row][col] = 1;
                    if(row > 0) {
                        rowWiseCount[row][col] += rowWiseCount[row - 1][col];
                    }
                    colWiseCount[row][col] = 1;
                    if(col > 0) {
                        colWiseCount[row][col] += colWiseCount[row][col - 1];
                    }
                }
            }
        }
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height = matrix.size();
        int weidth = matrix[0].size();
        populateRowAndColWiseOneCount(height, weidth, matrix);

        int maxSquareSide = 0;
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < weidth; col++) {
                if (matrix[row][col] == '0') {
                    continue;
                }
                maxSquare[row][col] = 1;
                maxSquareSide = max(maxSquareSide, maxSquare[row][col]);
                if (row == 0 || col == 0) {
                    continue;
                }
                int horizontalOneCount = rowWiseCount[row][col];
                int verticalOneCount = colWiseCount[row][col];
                maxSquare[row][col] =min(1 + maxSquare[row - 1][col - 1], min(horizontalOneCount, verticalOneCount));
                maxSquareSide = max(maxSquareSide, maxSquare[row][col]);
            }
        }
        return maxSquareSide*maxSquareSide;
    }
};



class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height = matrix.size();
        int weidth = matrix[0].size();
        vector<vector<int>> maxSquare(height, vector<int>(weidth, 0));
        vector<vector<int>> rowWiseCount(height, vector<int>(weidth, 0));
        vector<vector<int>> colWiseCount(height, vector<int>(weidth, 0));

        for(int row = 0; row < height; row++) {
            for(int col = 0; col < weidth; col++) {
                if(matrix[row][col] == '1') {
                    rowWiseCount[row][col] = 1;
                    if(row > 0) {
                        rowWiseCount[row][col] += rowWiseCount[row - 1][col];
                    }
                    colWiseCount[row][col] = 1;
                    if(col > 0) {
                        colWiseCount[row][col] += colWiseCount[row][col - 1];
                    }
                }
            }
        }

        int maxSquareSide = 0;
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < weidth; col++) {
                if (matrix[row][col] == '0') {
                    continue;
                }
                maxSquare[row][col] = 1;
                maxSquareSide = max(maxSquareSide, maxSquare[row][col]);
                if (row == 0 || col == 0) {
                    continue;
                }
                int horizontalOneCount = rowWiseCount[row][col];
                int verticalOneCount = colWiseCount[row][col];
                maxSquare[row][col] =min(1 + maxSquare[row - 1][col - 1], min(horizontalOneCount, verticalOneCount));
                // cout << row << " " << col << " " << maxSquare[row][col] << '\n';
                // cout << horizontalOneCount << " " << verticalOneCount << '\n';
                maxSquareSide = max(maxSquareSide, maxSquare[row][col]);
            }
        }
        return maxSquareSide*maxSquareSide;
    }
};
