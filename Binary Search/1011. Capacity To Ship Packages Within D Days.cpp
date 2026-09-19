// LeetCode 1011. Capacity To Ship Packages Within D Days
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Binary search on the answer: the shipping capacity. Feasibility check greedily
// counts how many days are needed for a given capacity.
class Solution
{
public:
    bool check(int capacity, vector<int> &weights, int days)
    {
        int day_cnt = 0, curr_cap = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (curr_cap + weights[i] > capacity)
            {
                day_cnt++;
                curr_cap = weights[i];
            }
            else
                curr_cap += weights[i];
        }

        if (curr_cap)
            day_cnt++;

        return day_cnt <= days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int low = 0, high = 0;
        for (int i = 0; i < n; i++)
        {
            low = max(low, weights[i]);
            high += weights[i];
        }
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid, weights, days))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};