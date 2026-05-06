class Solution {
private:
    const int INVALID = -1;
    string s1, s2, s3;
    vector<vector<int>> dp;
    int findInterLeave(int i, int j) {
        if(i == s1.size() && j == s2.size()) {
            return true;
        }

        int& canInterleave = dp[i][j];
        if(canInterleave != INVALID) {
            return canInterleave;
        }

        int k = i + j;
        canInterleave = 0;
        if(s1[i] == s3[k]) {
            canInterleave |= findInterLeave(i + 1, j);
        }
        if(s2[j] == s3[k]) {
            canInterleave |= findInterLeave(i, j + 1);
        }
        return canInterleave;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        dp.assign(s1.size() + 1, vector<int>(s2.size() + 1, INVALID));
        return findInterLeave(0, 0);
    }
};

class Solution {
private:
    vector<int> dp;
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }
        dp.assign(s2.size() + 1, 0);
        for(int i = 0; i <= s1.size(); i++) {
            for(int j = 0; j <= s2.size(); j++) {
                int k = i + j;
                if(i == 0 && j == 0) {
                    dp[j] = 1;
                }
                else if(i == 0) {
                    dp[j] = dp[j - 1] && (s2[j - 1] == s3[k - 1]);
                }
                else if(j == 0) {
                    dp[j] = dp[j] && (s1[i - 1] == s3[k - 1]);
                }
                else {
                    dp[j] = (dp[j - 1] && (s2[j - 1] == s3[k - 1])) || (dp[j] && (s1[i - 1] == s3[k - 1]));
                }
            }
        }
        return dp[s2.size()];
    }
};