class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int l = 0, r = 0, n = s.length();
        vector<int> hash(30, 0); // 0-25 uppercase s[i] - 'A' s[i] == 'A' hash[0], B = hash[1]....
        int ans = 0, maxf = 0;
        while (r < n)
        {
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);
            int required = r - l + 1 - maxf; // len = length of the subsstring, r - l + 1;
            while (required > k)
            {
                hash[s[l] - 'A']--;
                for (int i = 0; i < 26; i++)
                    maxf = max(maxf, hash[i]);
                l++;
                required = r - l + 1 - maxf;
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};