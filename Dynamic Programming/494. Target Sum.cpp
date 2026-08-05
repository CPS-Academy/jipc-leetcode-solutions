class Solution {
private:
    vector<int> nums;
    int target;
    map<pair<int, int>, int> dp; // dp[ {current_idx, current_sum} ] = ways;

    int findWays(int currentIndex, int currentSum) {
        // base case
        if(currentIndex == nums.size()) {
            return currentSum == target;
        }

        // memorization
        if(dp.count({currentIndex, currentSum})) {
            return dp[ {currentIndex, currentSum} ];
        }

        //transition
        int addCurrentValue = findWays(currentIndex + 1, currentSum + nums[currentIndex]);
        int substractCurrentValue = findWays(currentIndex + 1, currentSum - nums[currentIndex]);

        return dp[  {currentIndex, currentSum} ]  = addCurrentValue + substractCurrentValue;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        this->target = target;
        this->nums = nums;
        return findWays(0, 0);
    }
};


class Solution {
private:
    vector<int> nums;
    int target;
    map<int, int> dp; // dp[ {current_idx, current_sum} ] = ways;

    int getHash(int index, int sum) {
        return sum*100 + index;
    }

    int findWays(int currentIndex, int currentSum) {
        // base case
        if(currentIndex == nums.size()) {
            return currentSum == target;
        }

        // memorization
        int conjucateHashValue = getHash(currentIndex, currentSum);
        if(dp.count(conjucateHashValue)) {
            return dp[conjucateHashValue];
        }

        //transition
        int addCurrentValue = findWays(currentIndex + 1, currentSum + nums[currentIndex]);
        int substractCurrentValue = findWays(currentIndex + 1, currentSum - nums[currentIndex]);

        return dp[conjucateHashValue]  = addCurrentValue + substractCurrentValue;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        this->target = target;
        this->nums = nums;
        return findWays(0, 0);
    }
};