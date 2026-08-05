class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int l = 0, r = 0, n = fruits.size();
        vector<int> hash(100100, 0);
        int ans = 0, type = 0;

        while (r < n)
        {
            if (hash[fruits[r]] == 0)
                type++;
            hash[fruits[r]]++;

            while (type > 2)
            {
                hash[fruits[l]]--;
                if (hash[fruits[l]] == 0)
                    type--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};