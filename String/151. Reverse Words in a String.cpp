class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        for(auto& ch: s) {
            if(ch == ' ') {
                if(words.empty() || words.back() == " ") {
                    continue;
                }
                words.push_back(" ");
            }
            else {
                if(words.empty() || words.back() == " ") {
                    words.push_back("");
                }
                words.back() += ch;
            }
        }

        if(!words.empty() && words.back() == " ") {
            words.pop_back();
        }

        string reverseWords = "";
        for(int i = words.size() - 1; i >= 0; i--) {
            reverseWords += words[i];
        }
        return reverseWords;
    }
};