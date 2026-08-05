class Solution {
private:
    int INVALID = -1;
    string s;
    vector<vector<int>> dp;

    int findLongestPalindromeSubSeq(int L, int R) {
        // base case
        if(L == R) {
            return 1;
        }
        if(L > R) {
            return 0;
        }

        // memorization
        int& longestPalindrome = dp[L][R];
        if(longestPalindrome != INVALID) {
            return longestPalindrome;
        }
        if(s[L] == s[R]) {
            return longestPalindrome = 2 + findLongestPalindromeSubSeq(L + 1, R - 1);
        }
        return longestPalindrome = max(
            findLongestPalindromeSubSeq(L + 1, R),
            findLongestPalindromeSubSeq(L, R - 1));


    }
public:
    int longestPalindromeSubseq(string s) {
        this->s = s;
        int length = s.size();
        dp.assign(length, vector<int>(length, INVALID));
        return findLongestPalindromeSubSeq(0, length - 1);
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int length = s.size();
        vector<vector<int>> dp(length, vector<int>(length, 0));

        for(int L = length - 1; L >= 0; L--) {
            dp[L][L] = 1;
            for(int R = L + 1; R < length; R++) {
                if(s[L] == s[R]) {
                    dp[L][R] = 2 + dp[L + 1][R - 1];
                }
                else {
                    dp[L][R] = max(dp[L + 1][R], dp[L][R - 1]);
                }
            }
        }

        return dp[0][length - 1];
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int length = s.size();
        vector<int> dp(length), prevDp(length);

        for(int L = length - 1; L >= 0; L--) {
            dp[L] = 1;
            for(int R = L + 1; R < length; R++) {
                if(s[L] == s[R]) {
                    dp[R] = 2 + prevDp[R - 1];
                }
                else {
                    dp[R] = max(prevDp[R], dp[R - 1]);
                }
            }
            prevDp = dp;
        }

        return dp[length - 1];
    }
};