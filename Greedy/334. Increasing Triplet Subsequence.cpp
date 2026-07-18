class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstNum = INT_MAX;
        int secondNum = INT_MAX;
        for(auto& num: nums) {
            if(num <= firstNum) {
                firstNum = num;
            }
            else if(num <= secondNum) {
                secondNum = num;
            }
            else {
                return true;
            }
        }
        return false;
    }
};