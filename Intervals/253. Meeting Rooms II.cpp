class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> time_meetingUpdate;
        for(auto interval: intervals) {
            time_meetingUpdate.push_back({interval[0], 1});
            time_meetingUpdate.push_back({interval[1], -1});
        }
        sort(time_meetingUpdate.begin(), time_meetingUpdate.end());
        int maxOverlappingMeetings = 0;
        int prefixSum = 0;
        for(auto time_meetingPair: time_meetingUpdate) {
            prefixSum += time_meetingPair.second;
            maxOverlappingMeetings = max(maxOverlappingMeetings, prefixSum);
        }
        return maxOverlappingMeetings;
    }
};
