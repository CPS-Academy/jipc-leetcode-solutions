class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> letterFrequency;
        for(auto& ch: magazine) {
            letterFrequency[ch]++;
        }

        for(auto& ch: ransomNote) {
            letterFrequency[ch]--;
            if(letterFrequency[ch] < 0) {
                return false;
            }
        }
        return true;
    }
};