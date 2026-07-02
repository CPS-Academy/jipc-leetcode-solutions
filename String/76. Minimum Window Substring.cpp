class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) {
            return "";
        }

        int unique_letters_count = 0;
        unordered_map<char, int> freq_t;
        for(auto& ch: t) {
            if(!freq_t.count(ch)) {
                unique_letters_count++;
            }
            freq_t[ch]++;
        }
        unordered_map<char, int> freq_s;
        int letter_satisfied_condition = 0;
        for(int i = 0; i < t.size(); i++) {
            char& ch = s[i];
            freq_s[ch]++;
            if(freq_s[ch] == freq_t[ch]) {
                letter_satisfied_condition++;
            }
        }

        if(letter_satisfied_condition == unique_letters_count) {
            return s.substr(0, t.size());
        }

        int startIndex = -1, minWindowSize = s.size() + 1;
        for(int L = 0, R = t.size(); R < s.size(); R++) {
            char right_char = s[R];
            freq_s[right_char]++;
            if(freq_s[right_char] == freq_t[right_char]) {
                letter_satisfied_condition++;
            }
            while(letter_satisfied_condition == unique_letters_count) {
                if(R - L + 1 < minWindowSize) {
                    minWindowSize = R - L + 1;
                    startIndex = L;
                }
                char left_char = s[L];
                if(freq_s[left_char] == freq_t[left_char]) {
                    letter_satisfied_condition--;
                }
                freq_s[left_char]--;
                L++;
            }
        }

        if(startIndex == -1) {
            return "";
        }
        return s.substr(startIndex, minWindowSize);
    }
};