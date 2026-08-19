class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        // string ss = "", tt = "";
        int i = s.length() - 1, j = t.length() - 1;

        while (i >= 0 or j >= 0)
        {
            int h_cnt = 0;
            while (i >= 0)
            {
                if (s[i] == '#')
                {
                    h_cnt++;
                    i--;
                }
                else
                {
                    if (h_cnt > 0)
                    {
                        h_cnt--;
                        i--;
                    }
                    else
                        break;
                }
            }
            h_cnt = 0;

            while (j >= 0)
            {
                if (t[j] == '#')
                {
                    h_cnt++;
                    j--;
                }
                else
                {
                    if (h_cnt > 0)
                    {
                        h_cnt--;
                        j--;
                    }
                    else
                        break;
                }
            }
            if (i >= 0 and j >= 0)
            {
                if (s[i] != t[j])
                    return false;
            }
            else if (i >= 0 or j >= 0)
                return false;

            i--;
            j--;
        }

        return true;
    }
};