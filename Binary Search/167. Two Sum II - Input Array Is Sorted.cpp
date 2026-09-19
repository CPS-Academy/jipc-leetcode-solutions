// LeetCode 167. Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// For each element, binary search its complement in the remaining sorted range.
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        for (int i = 0; i < n - 1; i++)
        {
            int new_target = target - numbers[i];
            int pos = lower_bound(numbers.begin() + i + 1, numbers.end(), new_target) - numbers.begin();
            if (pos < n and numbers[pos] == new_target)
                return {i + 1, pos + 1};
        }

        return {};
    }
};