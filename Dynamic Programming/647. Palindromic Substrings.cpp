class Solution {
private:
    int findPalindromes(int L, int R, string& s) {
        int palindromicSubStringCount = 0;
        while(L >= 0 && R < s.size()) {
            if(s[L] != s[R]) {
                break;
            }
            palindromicSubStringCount++;
            L--; R++;
        }
        return palindromicSubStringCount;
    }
public:
    int countSubstrings(string s) { // T.C: O(N^2) S.C: O(1) / O(N)
        int palindromicSubStringCount = 0;
        for(int middlePoint = 0; middlePoint < s.size(); middlePoint++) {
            palindromicSubStringCount += findPalindromes(middlePoint, middlePoint, s) 
            + findPalindromes(middlePoint, middlePoint + 1, s);
        }
        return palindromicSubStringCount;
    }
};