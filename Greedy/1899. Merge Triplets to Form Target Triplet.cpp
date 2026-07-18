class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> current(3, 0);
        for(auto& triplet: triplets) {
            if(triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                current = { max(current[0], triplet[0]), max(current[1], triplet[1]), max(current[2], triplet[2]) };
            }
        }
        return current == target;
    }
};