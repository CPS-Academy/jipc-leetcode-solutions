class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> fullJustifiedResult;
        vector<string> currentRow;
        int currentRowLength = 0; // only words length and speces are excluded
        for(auto& word: words) {
            if(currentRowLength + currentRow.size() + word.size() > maxWidth) {
                // construct the line
                int totalSpaces = maxWidth - currentRowLength;
                string justifiedRow = "";
                if(currentRow.size() == 1) {
                    justifiedRow += currentRow.back();
                    justifiedRow.append(totalSpaces, ' ');
                }
                else{
                    int minimumWidthOfSpace = totalSpaces/(currentRow.size() - 1); // w1___w2___w3__w4
                    int extraWideSpaceCount = totalSpaces%(currentRow.size() - 1);
                    justifiedRow += currentRow[0];
                    for(int i = 1; i < currentRow.size(); i++) {
                        justifiedRow.append(minimumWidthOfSpace + (extraWideSpaceCount > 0), ' ');
                        extraWideSpaceCount--;
                        justifiedRow += currentRow[i];
                    }
                }
                fullJustifiedResult.push_back(justifiedRow);
                currentRow.clear();
                currentRowLength = 0;
            }
            currentRowLength += word.size();
            currentRow.push_back(word);
        }

        string lastLine = currentRow[0];
        for(int i = 1; i < currentRow.size(); i++) {
            lastLine += " " + currentRow[i];
        }
        lastLine.append(maxWidth - lastLine.size(), ' ');
        fullJustifiedResult.push_back(lastLine);
        
        return fullJustifiedResult;
    }
};