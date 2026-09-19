// LeetCode 875. Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/
// Binary search on the answer: eating speed k. Feasibility check computes
// total hours needed to eat every pile at speed k.
class Solution
{
public:
    bool check(int k, vector<int> &piles, int h)
    {
        long long cnt = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            cnt += (long long)piles[i] / k;
            if (piles[i] % k)
                cnt++;
        }

        return (cnt <= h ? true : false);
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = 1e9;
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid, piles, h))
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