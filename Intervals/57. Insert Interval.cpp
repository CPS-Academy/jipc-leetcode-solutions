class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int intervalLength = intervals.size();
        vector<vector<int>> updatedIntervals;

        int index = 0;
        while(index < intervalLength && intervals[index][1] < newInterval[0]) {
            updatedIntervals.push_back(intervals[index]);
            index++;
        }

        // Merging the overlapping intervals
        while(index < intervalLength && intervals[index][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        updatedIntervals.push_back(newInterval);

        while(index < intervalLength) {
            updatedIntervals.push_back(intervals[index]);
            index++;
        }

        return updatedIntervals;
    }
};
