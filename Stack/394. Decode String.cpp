class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> frequency_string_stack;
        int duplicateValue = 0;
        frequency_string_stack.push({1, ""});

        for(auto& ch: s) {
            if('0' <= ch && ch <= '9') {
                duplicateValue = 10*duplicateValue + ch - '0';
            }
            else if('a' <= ch && ch <= 'z') {
                frequency_string_stack.top().second += ch;
            }
            else if(ch == ']') {
                pair<int, string> frequencyStringPair = frequency_string_stack.top();
                frequency_string_stack.pop();
                int duplicattionFactor = frequencyStringPair.first - 1;
                string duplicatedString = frequencyStringPair.second;
                while(duplicattionFactor--) {
                    duplicatedString += frequencyStringPair.second;
                }
                frequency_string_stack.top().second += duplicatedString;
            }
            else {
                frequency_string_stack.push({duplicateValue, ""});
                duplicateValue = 0;
            }
        }

        return frequency_string_stack.top().second;
    }
};
