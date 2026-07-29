class Solution {
private:
    vector<vector<int>> combinations;
    vector<int> currentCombination;
    void findCombinations(int index, int target, vector<int>& candidates) {
        if(index == candidates.size()) {
            if(target == 0) {
                combinations.push_back(currentCombination);
            }
            return;
        }
        if(candidates[index] <= target) {
            currentCombination.push_back(candidates[index]);
            findCombinations(index, target - candidates[index], candidates);
            currentCombination.pop_back();
        }
        findCombinations(index + 1, target, candidates);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        findCombinations(0, target, candidates);
        return combinations;
    }
};