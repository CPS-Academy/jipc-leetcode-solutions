class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (p.length() > s.length())
            return {};

        vector<int> f_s(30, 0), f_p(30, 0);
        vector<int> ans;

        for (int i = 0; i < p.length(); i++)
        {
            f_p[p[i] - 'a']++;
            f_s[s[i] - 'a']++;
        }

        if (f_p == f_s)
            ans.push_back(0);
        int prev = 0;

        for (int i = p.length(); i < s.length(); i++)
        {
            f_s[s[i] - 'a']++;
            f_s[s[prev] - 'a']--;

            if (f_p == f_s)
                ans.push_back(prev + 1);
            prev++;
        }

        return ans;
    }
};