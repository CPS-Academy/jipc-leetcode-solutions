// LeetCode 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/
// Binary search over prefix sums (O(n log n)); nums are all positive so prefix sums are strictly increasing.
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int low = 1;
        int high = n;
        int ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (check(target, nums, mid) == true)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }

    bool check(int target, vector<int> &nums, int subLength)
    {
        int sum = 0;
        for (int i = 0; i < subLength; i++)
            sum += nums[i];

        if (sum >= target)
            return true;

        for (int i = subLength; i < nums.size(); i++)
        {
            sum += nums[i];
            sum -= nums[i - subLength];

            if (sum >= target)
                return true;
        }

        return false;
    }
};