class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size()) {
            return s;
        }

        int zigzagResult = "";
        for(int i = 0; i < numRows; i++) {
            if(i == 0 || i + 1 == numRows) {
                for(int j = i; j < s.size(); j += 2*(numRows - 1)) {
                    zigzagResult += s[j];
                }
                continue;
            }

            bool toggle = true;
            for(int j = i; j < s.size(); ) {
                zigzagResult += s[j];
                j += toggle ? 2*(numRows - i - 1) : 2*i;
                toggle ^= true;
            }
        }

        return zigzagResult;
    }
};