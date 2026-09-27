class Solution {
private:
    int MAX_VALUE_LIMIT = 1000;
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) { // O(MAX_VALUE)
        vector<int> frequency(MAX_VALUE_LIMIT + 1, 0);
        for(auto& value: arr1) { // O(SIZE_OF_ARRAY_1)
            frequency[value]++;
        }

        vector<int> relativeSortedArray;
        for(auto& value: arr2) { // O(SIZE_OF_ARRAY_1)
            while(frequency[value]) {
                relativeSortedArray.push_back(value);
                frequency[value]--;
            }
        }

        for(int value = 0; value <= MAX_VALUE_LIMIT; value++) { // O(MAX_VALUE)
            while(frequency[value]) {
                relativeSortedArray.push_back(value);
                frequency[value]--;
            }
        }

        return relativeSortedArray;
    }
};
