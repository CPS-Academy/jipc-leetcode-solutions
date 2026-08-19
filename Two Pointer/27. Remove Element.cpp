class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int left = 0, right = 0;
        int n = nums.size();
        while (right < n)
        {
            if (nums[right] != val)
            {
                nums[left] = nums[right];
                left++;
            }
            right++;
        }

        return left;
    }
};