class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int shotCount = 1;
        int prev_shot_position = points[0][1];
        for(auto& point: points) {
            if(prev_shot_position < point[0]) {
                shotCount++;
                prev_shot_position = point[1];
            }
        }
        return shotCount;
    }
};