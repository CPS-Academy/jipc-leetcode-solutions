// LeetCode 540. Single Element in a Sorted Array
// https://leetcode.com/problems/single-element-in-a-sorted-array/
// Pairs line up at (even, odd) indices before the single element and
// (odd, even) indices after it; binary search for where that pattern breaks.
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int high = n - 1;
        int low = 0;
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mid % 2)
                mid--;

            if (nums[mid] == nums[mid + 1])
                low = mid + 2;
            else
            {
                ans = nums[mid];
                high = mid - 1;
            }
        }
        return ans;
    }
};