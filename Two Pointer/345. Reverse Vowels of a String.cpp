class Solution
{
public:
    string reverseVowels(string s)
    {
        map<int, bool> mp;
        mp['a'] = true;
        mp['e'] = true;
        mp['i'] = true;
        mp['o'] = true;
        mp['u'] = true;

        mp['A'] = true;
        mp['E'] = true;
        mp['I'] = true;
        mp['O'] = true;
        mp['U'] = true;

        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (mp.find(s[i]) != mp.end() && mp.find(s[j]) != mp.end())
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if (mp.find(s[i]) == mp.end())
                i++;
            else if (mp.find(s[j]) == mp.end())
                j--;
            else
            {
                i++;
                j--;
            }
        }

        return s;
    }
};