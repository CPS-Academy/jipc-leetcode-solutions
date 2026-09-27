class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged_intervals;
        int intervalStart = intervals[0][0], intervalEnd = intervals[0][1];
        for(auto& interval: intervals) {
            if(intervalEnd < interval[0]) {
                merged_intervals.push_back({intervalStart, intervalEnd});
                intervalStart = interval[0];
            }
            intervalEnd = max(intervalEnd, interval[1]);
        }
        merged_intervals.push_back({intervalStart, intervalEnd});
        return merged_intervals;
    }
};
