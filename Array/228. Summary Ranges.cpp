class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> summary_ranges;
        int i = 0;
        while(i < nums.size()) {
            int range_start_index = i;
            int range_end_index = i;
            
            int j = i + 1;
            while(j < nums.size() && nums[j - 1] + 1 == nums[j]) {
                j++;
            }
            range_end_index = j - 1;
            
            summary_ranges.push_back(to_string(nums[range_start_index]));
            if(range_start_index != range_end_index) {
                summary_ranges.back() += "->" + to_string(nums[range_end_index]);
            }
            i = range_end_index + 1;
        }
        return summary_ranges;
    }
};