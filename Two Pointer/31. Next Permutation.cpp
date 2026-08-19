class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int l = n - 2, r = n - 1;
        // Find pivotal point
        while (l >= 0 and nums[l] >= nums[l + 1])
            l--;

        // Find next greater element
        if (l >= 0)
        {
            while (nums[r] <= nums[l])
                r--;

            swap(nums[r], nums[l]);
        }

        // reverse the next
        l++;
        reverse(nums.begin() + l, nums.end());
    }
};