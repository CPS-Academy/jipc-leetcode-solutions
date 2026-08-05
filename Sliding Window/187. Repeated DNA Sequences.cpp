class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> mp;
        int n = s.length();
        string window = "";
        for (int i = 0; i < n; i++)
        {
            window += s[i];
            if (i >= 9)
            {
                if (i == 9)
                    mp[window]++;
                else
                {
                    window.erase(0, 1);
                    mp[window]++;
                }
            }
        }

        vector<string> ans;
        for (auto i : mp)
        {
            if (i.second >= 2)
                ans.push_back(i.first);
        }

        return ans;
    }
};