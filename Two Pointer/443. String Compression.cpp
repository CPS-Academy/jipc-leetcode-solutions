class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int left = 0, right = 0;

        while (right < n)
        {
            char c = chars[right];
            int cnt = 0;

            while (right < n and chars[right] == c)
            {
                cnt++;
                right++;
            }

            chars[left] = c;
            left++;

            if (cnt > 1)
            {
                string s = to_string(cnt);
                for (char ch : s)
                {
                    chars[left] = ch;
                    left++;
                }
            }
        }

        return left;
    }
};