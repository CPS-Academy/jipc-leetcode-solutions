class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();

        int left = 0, right = n - 1;

        int mid = 0; // to traverse the array and find position for 1

        while (mid <= right)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[left]);
                left++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[right]);
                right--;
            }
        }
    }
};