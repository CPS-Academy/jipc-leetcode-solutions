class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ans = 0, l = 0, r = 0;
        while (r < nums.size())
        {
            if (nums[r] == 0)
            {
                l = r + 1;
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};