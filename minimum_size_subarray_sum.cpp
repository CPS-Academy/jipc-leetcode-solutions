class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int l = 0, r = 0, n = nums.size();
        int ans = n + 1, sum = 0;
        while (r < n)
        {
            sum += nums[r];
            while (sum > target)
            {
                sum -= nums[l];
                ans = min(ans, r - l + 1);
                l++;
            }

            if (sum == target)
                ans = min(ans, r - l + 1);

            r++;
        }

        return ans == n + 1 ? 0 : ans;
    }
};