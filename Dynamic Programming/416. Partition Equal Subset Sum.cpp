class Solution {
private:
    int INVALID = -1;
    vector<int> nums;
    vector<vector<int>> dp;

    int isValidParititionExists(int idx, int remaining) {
        if(remaining == 0) {
            return true;
        }
        if(idx == nums.size()) {
            return false;
        }

        int& ret = dp[idx][remaining];
        if(ret != INVALID) {
            return ret;
        }

        ret = isValidParititionExists(idx + 1, remaining);
        if(nums[idx] <= remaining) {
            ret |= isValidParititionExists(idx + 1, remaining - nums[idx]);
        }

        return ret;
    }

public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(auto& num: nums) {
            totalSum += num;
        }
        if(totalSum&1) {
            return false;
        }

        int target = (totalSum>>1);

        this->nums = nums;
        int length = nums.size();
        dp.assign(length, vector<int>(target + 1, INVALID));

        return isValidParititionExists(0, target);
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(auto& num: nums) {
            totalSum += num;
        }
        if(totalSum&1) {
            return false;
        }

        int target = (totalSum>>1);

        int length = nums.size();
        vector<vector<int>> dp(length + 1, vector<int>(target + 1, 0));

        dp[length][0] = 1;
        for(int idx = length - 1; idx >= 0; idx--) {
            for(int remainingValue = 0; remainingValue <= target; remainingValue++) {
                dp[idx][remainingValue] = dp[idx + 1][remainingValue];
                if(remainingValue >= nums[idx]) {
                    dp[idx][remainingValue] |= dp[idx + 1][remainingValue - nums[idx]];
                }
            }
        }

        return dp[0][target];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(auto& num: nums) {
            totalSum += num;
        }
        if(totalSum&1) {
            return false;
        }

        int target = (totalSum>>1);

        int length = nums.size();
        vector<int> dp(target + 1, 0), prevDp(target + 1, 0);

        prevDp[0] = 1;
        for(int idx = length - 1; idx >= 0; idx--) {
            for(int remainingValue = 0; remainingValue <= target; remainingValue++) {
                dp[remainingValue] = prevDp[remainingValue];
                if(remainingValue >= nums[idx]) {
                    dp[remainingValue] |= prevDp[remainingValue - nums[idx]];
                }
            }
            prevDp = dp;
        }

        return dp[target];
    }
};