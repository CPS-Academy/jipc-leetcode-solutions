// LeetCode 658. Find K Closest Elements
// https://leetcode.com/problems/find-k-closest-elements/
// Binary search the starting index of the k-length window closest to x.
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();

        vector<int> ans;
        for (int i = pos; i < pos + k; i++)
            ans.push_back(arr[i]);

        return ans;
    }
};