class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool isOneExist = false;
        for(auto& num: nums) {
            if(num == 1) {
                isOneExist = true;
                break;
            }
        }
        if(!isOneExist) {
            return 1;
        }

        for(auto& num: nums) {
            if(num <= 0 || nums.size() < num) {
                num = 1;
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            int absValue = abs(nums[i]);
            if(absValue == nums.size()) {
                nums[0] = -abs(nums[0]);
            }
            else {
                nums[absValue] = -abs(nums[absValue]);
            }
        }

        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] > 0) {
                return i;
            }
        }

        if(nums[0] > 0) {
            return nums.size();
        }

        return nums.size() + 1;
    }
};