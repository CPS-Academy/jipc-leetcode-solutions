class Solution {
public:
    bool isValid(string s) {
        stack<int> openingBrackets;

        unordered_set<int> openingBracketSet;
        openingBracketSet.insert('(');
        openingBracketSet.insert('{');
        openingBracketSet.insert('[');

        unordered_map<int, int> closingToOpeningBracketMap;
        closingToOpeningBracketMap[')'] = '(';
        closingToOpeningBracketMap['}'] = '{';
        closingToOpeningBracketMap[']'] = '[';

        for(auto& ch: s) {
            if(openingBracketSet.count(ch)) {
                openingBrackets.push(ch);
            }
            else if(!openingBrackets.empty() && openingBrackets.top() == closingToOpeningBracketMap[ch]) {
                openingBrackets.pop();
            }
            else {
                return false;
            }
        }

        return openingBrackets.empty();
    }
};
