// LeetCode 528. Random Pick with Weight
// https://leetcode.com/problems/random-pick-with-weight/
// Build a prefix-sum array of weights, then binary search the lower bound
// of a random target drawn uniformly from [1, total].
class Solution
{
public:
    vector<int> pre;
    Solution(vector<int> &w)
    {
        pre.push_back(w[0]);
        for (int i = 1; i < w.size(); i++)
            pre.push_back(w[i] + pre[i - 1]);
    }

    int pickIndex()
    {
        int target = rand() % pre.back() + 1;
        int pos = lower_bound(pre.begin(), pre.end(), target) - pre.begin();

        return pos;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */