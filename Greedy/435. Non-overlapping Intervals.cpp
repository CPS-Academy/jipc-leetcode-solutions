class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int nonOverlappingCount = 0;
        int lastOccupiedPlace = INT_MIN;
        for(auto& interval: intervals) {
            if(lastOccupiedPlace <= interval[0]) {
                lastOccupiedPlace = interval[1];
                nonOverlappingCount++;
            }
        }

        return intervals.size() - nonOverlappingCount;
    }
};