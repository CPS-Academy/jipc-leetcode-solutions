class Solution {
public:
    string removeKdigits(string nums, int k) {
        string smallestNum;
        for(auto& num: nums) { // T.C: O(N) S.C: O(N)
            while(k > 0 && !smallestNum.empty() && num < smallestNum.back()) {
                k--;
                smallestNum.pop_back();
            }
            if((smallestNum.empty() && num != '0') || !smallestNum.empty()) {
                smallestNum.push_back(num);
            }
        }
        while(k > 0 && !smallestNum.empty()) {
            k--;
            smallestNum.pop_back();
        }
        return smallestNum.empty() ? "0" : smallestNum;
    }
};