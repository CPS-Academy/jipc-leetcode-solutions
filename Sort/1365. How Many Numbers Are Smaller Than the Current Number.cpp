class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) { // O(N + MAX_LIMIT)
        // frequency: {index, value} = {value of nums, frequency}
        // frequency[1] = 1
        // frequency[2] = 2 + 1 = 3
        // frequency[3] = 1 + 3 = 4
        // frequency[4] = 4 + 0 = 4
        // frequency[5] = 4 + 0 = 4
        // frequency[6] = 4 + 0 = 4
        // frequency[7] = 4 + 0 = 4
        // frequency[8] = 1 + 4 = 5

        vector<int> frequency(101, 0);
        for(auto& num: nums) {
            frequency[num]++;
        }

        for(int i = 1; i < 101; i++) {
            frequency[i] += frequency[i - 1];
        }

        vector<int> smallerNumbers;
        for(auto& num: nums) {
            int value = num == 0 ? 0 : frequency[num - 1];
            smallerNumbers.push_back(value);
        }
        return smallerNumbers;
    }
};
