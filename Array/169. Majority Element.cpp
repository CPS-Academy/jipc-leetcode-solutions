class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner = -1, difference = 0;
        for(auto& num: nums) {
            if(difference == 0) {
                winner = num;
                difference = 1;
            }
            else if(num == winner) {
                difference++;
            }
            else {
                difference--;
            }
        }
        return winner;
    }
};