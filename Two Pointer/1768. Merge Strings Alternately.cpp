class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int n = word1.length(), m = word2.length();
        int i = 0, j = 0;
        string s = "";

        while (i < n and j < m)
        {
            if (s.length() % 2 == 0)
            {
                s += word1[i];
                i++;
            }
            else
            {
                s += word2[j];
                j++;
            }
        }

        while (i < n)
        {
            s += word1[i];
            i++;
        }
        while (j < m)
        {
            s += word2[j];
            j++;
        }

        return s;
    }
};