class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_visited_right_index = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(max_visited_right_index < i) {
                return false;
            }
            max_visited_right_index = max(max_visited_right_index, i + nums[i]);
        }
        return true;
    }
};