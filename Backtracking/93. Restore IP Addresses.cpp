class Solution {
private:
    const int MAX_IP_LIMIT = 255;
    const int MAX_IP_PARTS = 4;
    const int MAX_DIGIT_LENGTH = 3;

    vector<string> restoredIpAddresses;
    string currentIpAddress;

    void restore(int index, string& s, int partCount) {
        if(index == s.size()) {
            if(partCount == MAX_IP_PARTS) {
                restoredIpAddresses.push_back(currentIpAddress);
            }
            return;
        }

        int digitCount = 1;
        int number = s[index] - '0';
        while(digitCount <= MAX_DIGIT_LENGTH && index + digitCount <= s.size() && number <= MAX_IP_LIMIT) {
            if(s[index] == '0' && digitCount > 1) {
                break;
            }

            if(index != 0) {
                currentIpAddress.push_back('.');
            }
            currentIpAddress += to_string(number);

            restore(index + digitCount, s, partCount + 1);

            int popDigitCount = digitCount;
            while(popDigitCount--) {
                currentIpAddress.pop_back();
            }
            if(index != 0) {
                currentIpAddress.pop_back();
            }

            number = 10*number + s[ index + digitCount ] - '0';
            digitCount++;
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        restore(0, s, 0);
        return restoredIpAddresses;
    }
};