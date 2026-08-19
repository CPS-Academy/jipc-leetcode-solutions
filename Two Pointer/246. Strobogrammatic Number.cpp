class Solution
{
public:
    bool isStrobogrammatic(string num)
    {
        int n = num.length();
        vector<int> v(11, -1);
        v[0] = 0;
        v[1] = 1;
        v[6] = 9;
        v[8] = 8;
        v[9] = 6;

        // 2, 3, 4, 5, 7 -> -1

        int left = 0, right = n - 1;
        while (left <= right)
        {
            if (v[num[left] - '0'] == -1)
                return false;

            if (v[num[left] - '0'] != num[right] - '0')
                return false;

            left++;
            right--;
        }

        return true;
    }
};