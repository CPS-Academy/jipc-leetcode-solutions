class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string validClosing = "";
        int openingCount = 0, imbalancedOpening = 0;
        for(auto& ch: s) {
            if(ch == '(') {                 /// ((( ))
                openingCount++;
                imbalancedOpening++;
            }
            if(ch == ')') {
                if(imbalancedOpening <= 0) {
                    continue;
                }
                imbalancedOpening--;
            }
            validClosing += ch;
        }

        int validOpening = openingCount - imbalancedOpening;
        string balanced = "";
        for(auto& ch: validClosing) {
            if(ch == '(') {
                if(validOpening <= 0) {
                    continue;
                }
                validOpening--;
            }
            balanced += ch;
        }

        return balanced;
    }
};