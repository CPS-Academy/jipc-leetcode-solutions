class Solution
{
public:
    bool check(vector<int> &f_s1, vector<int> &f_s2)
    {
        for (int i = 0; i < 26; i++)
        {
            if (f_s1[i] != f_s2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;

        vector<int> f_s1(30, 0), f_s2(30, 0);
        for (int i = 0; i < s1.length(); i++)
        {
            f_s1[s1[i] - 'a']++; // 0 - 25
            f_s2[s2[i] - 'a']++;
        }

        if (check(f_s1, f_s2))
            return true;

        for (int i = s1.length(), prev = 0; i < s2.length(); i++, prev++)
        {
            f_s2[s2[i] - 'a']++;
            f_s2[s2[prev] - 'a']--;
            if (check(f_s1, f_s2))
                return true;
        }
        return false;
    }
};