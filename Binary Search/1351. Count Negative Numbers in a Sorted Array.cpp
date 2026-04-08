class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            int ind = upper_bound(grid[i].begin(), grid[i].end(), 0, greater<int>()) - grid[i].begin();
            cnt += grid[i].size() - ind;
        }
        return cnt;
    }
};
