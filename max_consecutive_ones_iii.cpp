class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = 0, r = 0, n = nums.size();
        int ans = 0, sum = 0;

        while (r < n)
        {
            sum += nums[r];
            int zero = r - l + 1 - sum;
            while (zero > k)
            {
                sum -= nums[l];
                l++;
                zero = r - l + 1 - sum;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};