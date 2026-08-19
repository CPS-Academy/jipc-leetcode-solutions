class Solution
{
public:
    bool validWordAbbreviation(string word, string abbr)
    {
        int n = word.length(), m = abbr.length();
        int i = 0, j = 0;
        while (i < n and j < m)
        {
            if (isalpha(abbr[j]))
            {
                if (word[i] != abbr[j])
                    return false;
                i++;
                j++;
            }
            else
            {
                if (abbr[j] == '0')
                    return false;

                int cnt = 0;
                while (j < m and isdigit(abbr[j]))
                {
                    cnt = cnt * 10 + (abbr[j] - '0');
                    j++;
                }
                i += cnt;
            }
        }

        return i == n and j == m;
    }
};