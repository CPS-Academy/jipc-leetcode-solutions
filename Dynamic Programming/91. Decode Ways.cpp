class Solution {
    public:
        int numDecodings(string s) {
            s = '$' + s;
            vector<int> ways(2, 0);
            ways[0] = 1;
            ways[1] = (s[1] != '0');
            for(int i = 2; i < s.size(); i++) {
                int currentWays = 0;
                if(s[i] != '0') {
                    currentWays += ways[1];
                }
                int value = stoi(s.substr(i - 1, 2));
                if(s[i - 1] != '0' && 1 <= value && value <= 26) {
                    currentWays += ways[0];
                }

                ways[0] = ways[1];
                ways[1] = currentWays;
            }
            return ways[1];
        }
};