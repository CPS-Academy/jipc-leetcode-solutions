class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)return 0;
        int low = 0, high = nums.size() - 1;
        if(nums[low] > nums[low+1])return low;
        if(nums[high] > nums[high-1])return high;

        low++;
        high--;

        int ans = -1;

        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])return mid;
            else if(nums[mid] < nums[mid+1])low = mid + 1;
            else high = mid - 1;
        }

        return ans;
    }
};
