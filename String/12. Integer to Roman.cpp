class Solution {
public:
    string intToRoman(int num) {
        map<int, string> intToRomanMap;
        intToRomanMap[1] = "I";

        intToRomanMap[4] = "IV";
        intToRomanMap[5] = "V";

        intToRomanMap[9] = "IX";
        intToRomanMap[10] = "X";

        intToRomanMap[40] = "XL";
        intToRomanMap[50] = "L";

        intToRomanMap[90] = "XC";
        intToRomanMap[100] = "C";

        intToRomanMap[400] = "CD";
        intToRomanMap[500] = "D";

        intToRomanMap[900] = "CM";
        intToRomanMap[1000] = "M";

        string roman = "";
        while(num > 0) {
            auto key_value = intToRomanMap.rbegin();
            while(key_value != intToRomanMap.rend()) {
                if(key_value->first <= num) {
                    num -= key_value->first;
                    roman += key_value->second;
                    break;
                }
                key_value++;
            }
        }
        return roman;
    }
};