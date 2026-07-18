class Solution {
public:
    int longestPalindrome(string s) { 
        unordered_map<char, int> letter_frequency_map;
        for(auto& ch: s) {
            letter_frequency_map[ch]++;
        }
        int max_palindrome_length = 0;
        bool isOddLengthExist = false;
        for(auto& letter_frequency: letter_frequency_map) {
            int frequency = letter_frequency.second;
            if(frequency&1) {
                isOddLengthExist = true;
            }
            int length = frequency&1 ? frequency - 1 : frequency;
            max_palindrome_length += length;
        }
        return isOddLengthExist + max_palindrome_length;
    }
};