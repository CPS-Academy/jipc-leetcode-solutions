class Solution {
private:
    const int INVALID = -1;
    string s, t;
    vector<vector<int>> dp;
    int findDistinctSubSequences(int i, int j) {
        // base case
        if(j == t.size()) {
            return 1;
        }
        if(i == s.size()) {
            return 0;
        }
        
        // memorization
        int& distinctSeqCount = dp[i][j];
        if(distinctSeqCount != INVALID) {
            return distinctSeqCount;
        }

        // transition
        distinctSeqCount = findDistinctSubSequences(i + 1, j);
        if(s[i] == t[j]) {
            distinctSeqCount += findDistinctSubSequences(i + 1, j + 1);
        }
        return distinctSeqCount;
    }
public:
    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;
        dp.assign(s.size(), vector<int>(s.size(), INVALID));
        return findDistinctSubSequences(0, 0);
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<unsigned int> currentRowStore(t.size() + 1), nextRowStored(t.size() + 1);
        nextRowStored[ t.size() ] = 1;
        for(int i = s.size() - 1; i >= 0; i--) {
            currentRowStore[ t.size() ] = 1;
            for(int j = 0; j < t.size(); j++) {
                currentRowStore[j] = nextRowStored[j];
                if(s[i] == t[j]) {
                    currentRowStore[j] += nextRowStored[j + 1];
                }
            }
            nextRowStored = currentRowStore;
        }
        return currentRowStore[0];
    }
};