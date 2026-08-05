class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> hash(256, 0);
        int left = 0, right = 0;
        int ans = 0;
        while (right < s.length())
        {
            while (hash[s[right]] > 0)
            {
                hash[s[left]]--;
                left++;
            }
            hash[s[right]]++;
            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};