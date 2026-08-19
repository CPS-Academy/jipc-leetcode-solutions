class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 and nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 and nums[j] == nums[j - 1])
                    continue;

                int sum1 = nums[i] + nums[j];
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    long long sum = (long long)sum1 + nums[left] + nums[right];
                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right and nums[left] == nums[left - 1])
                            left++;
                        while (left < right and nums[right] == nums[right + 1])
                            right--;
                    }
                    else if (sum > target)
                        right--;
                    else
                        left++;
                }
            }
        }

        return ans;
    }
};