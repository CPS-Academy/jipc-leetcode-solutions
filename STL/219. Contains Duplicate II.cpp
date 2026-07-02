class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int length = nums.size();
        unordered_set<int> valueSet;
        for(int i = 0, j = 0; j < length; j++) {
            if(j - i > k) {
                valueSet.erase(nums[i]);
                i++;
            }
            int value = nums[j];
            if(valueSet.count(value))  {
                return true;
            }
            valueSet.insert(value);
        }
        return false;
    }
};