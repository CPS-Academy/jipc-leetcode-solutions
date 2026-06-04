class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastIndex = 0;
        int consecutiveMatchCount = 0;
        int length = nums.size();
        for(int currentIndex = 1; currentIndex < length; currentIndex++) {
            if(nums[currentIndex] == nums[lastIndex]) {
                consecutiveMatchCount++;
                if(consecutiveMatchCount < 2) {
                    lastIndex++;
                    nums[lastIndex] = nums[currentIndex];
                }
            }
            else {
                consecutiveMatchCount = 0;
                lastIndex++;
                nums[lastIndex] = nums[currentIndex];
            }
        }
        return lastIndex + 1;
    }
};