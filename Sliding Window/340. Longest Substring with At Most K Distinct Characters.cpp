class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        int n = s.length(), l = 0, r = 0;
        vector<int> hash(256, 0);
        int ans = 0, unique = 0;

        while (r < n)
        {
            if (hash[s[r]] == 0)
                unique++;
            hash[s[r]]++;

            while (unique > k)
            {
                hash[s[l]]--;
                if (hash[s[l]] == 0)
                    unique--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};