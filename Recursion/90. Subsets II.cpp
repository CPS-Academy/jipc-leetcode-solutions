class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> allSubsetCollection;
        set<vector<int>> powerSet;
        int n = nums.size();
        for(int combinationCounter = 0; combinationCounter < (1 << n); combinationCounter++) {
            vector<int> currentSet;
            for(int index = 0; index < n; index++) {
                if(!((1 << index)&combinationCounter)) {
                    continue;
                }
                currentSet.push_back(nums[index]);
            }
            if(!powerSet.count(currentSet)) {
                allSubsetCollection.push_back(currentSet);
                powerSet.insert(currentSet);
            }
        }
        return allSubsetCollection;
    }
};