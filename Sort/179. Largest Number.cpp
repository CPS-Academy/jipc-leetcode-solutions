class Solution {
private:
    bool static compare(int& a, int& b) {
        string str_a = to_string(a);
        string str_b = to_string(b);
        return str_a + str_b > str_b + str_a;
    }
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        if(nums[0] == 0) {
            return "0";
        }

        string largestNumber = "";
        for(int& num: nums) {
            largestNumber += to_string(num);
        }
        return largestNumber;
    }
};
