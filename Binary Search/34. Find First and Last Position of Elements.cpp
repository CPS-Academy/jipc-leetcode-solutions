class Solution {
public:
    ///left
    int findStart(vector<int>& nums, int target) {
        int high = nums.size() - 1, low = 0;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target)high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }

    ///right
    int findEnd(vector<int>& nums, int target) {
        int high = nums.size() - 1, low = 0;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target)high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findStart(nums, target);
        int end = findEnd(nums, target);

        return {start, end};
    }
};
