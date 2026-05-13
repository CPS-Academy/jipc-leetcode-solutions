class Solution {
private:
    vector<int> nums;
    int findMaxProfit(int startingHouse, int endingHouse) {
        int maxProfitByRobbingFromTheFirstToPreviousHouse = 0;
        int maxProfitByRobbingFromTheFirstToTwoHouseBack = 0;
        for(int i = startingHouse; i < endingHouse; i++) {
            int temp = maxProfitByRobbingFromTheFirstToPreviousHouse;
            maxProfitByRobbingFromTheFirstToPreviousHouse = 
                max(maxProfitByRobbingFromTheFirstToPreviousHouse, nums[i] + maxProfitByRobbingFromTheFirstToTwoHouseBack);
            maxProfitByRobbingFromTheFirstToTwoHouseBack = temp;
        }
        return maxProfitByRobbingFromTheFirstToPreviousHouse;   
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        this->nums = nums;
        return max(findMaxProfit(0, nums.size() - 1), findMaxProfit(1, nums.size()));
    }
};


class Solution {
private:
    const int INVALID = -1;
    vector<vector<int>> dp;
    vector<int> nums;
    int hasFirstHouseRobbed;
    int findMaxProfit(int idx, int hasPreviousHouseRobbed) {
        // base case
        if(idx == nums.size()) {
            return 0;
        }

        // memorization
        int &ret = dp[idx][hasPreviousHouseRobbed];
        if(ret != INVALID) {
            return ret;
        }

        // transitions
        if(hasPreviousHouseRobbed) { // Not rob
            return ret = findMaxProfit(idx + 1, 0);
        }
        if(idx + 1 == nums.size()) {
            if(hasFirstHouseRobbed) {
                return ret = findMaxProfit(idx + 1, 0);
            }
            return ret = nums[idx] + findMaxProfit(idx + 1, 1);
        }
        // Rob or not
        return ret = max(nums[idx] + findMaxProfit(idx + 1, 1), findMaxProfit(idx + 1, 0));
    }

public:
    int rob(vector<int>& nums) {
        int houseCount = nums.size();
        this->nums = nums;
        dp.assign(houseCount, vector<int>(2, INVALID));

        hasFirstHouseRobbed = 1;
        int maxProfitByRobbingFirstHouse = nums[0] + findMaxProfit(1, 1);

        dp.assign(houseCount, vector<int>(2, INVALID));

        hasFirstHouseRobbed = 0;
        int maxProfitByNotRobbitFirstHouse = findMaxProfit(1, 0);

        return max(maxProfitByRobbingFirstHouse, maxProfitByNotRobbitFirstHouse);
    }
};