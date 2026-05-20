class Solution {
private:
    int INVALID = -1;
    int n;
    vector<vector<int>> taskSchedule;
    vector<int> start;
    vector<int> dp;
    
    int findMaxProfit(int taskIndex) { // T.C: O(NlogN) S.C: O(N)
        //base case
        if(taskIndex == n) {
            return 0;
        }

        // memorization
        int& maxProfit = dp[taskIndex];
        if(maxProfit != -1) {
            return maxProfit;
        }

        // tansition
        int nextTaskIndex = lower_bound(start.begin(), start.end(), taskSchedule[taskIndex][1]) - start.begin();
        int takeTheTask = taskSchedule[taskIndex][2] + findMaxProfit(nextTaskIndex);
        int notTakeTheTask = findMaxProfit(taskIndex + 1);

        return maxProfit = max(takeTheTask, notTakeTheTask);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        this->n = startTime.size();
        dp.assign(n, INVALID);
        for(int i = 0; i < startTime.size(); i++) {
            taskSchedule.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(taskSchedule.begin(), taskSchedule.end());
        start = startTime;
        sort(start.begin(), start.end());

        return findMaxProfit(0);
    }
};