class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(length > 0 && s[i] == ' ') {
                return length;
            }
            if(s[i] != ' ') {
                length++;
            }
        }
        return length;
    }
};