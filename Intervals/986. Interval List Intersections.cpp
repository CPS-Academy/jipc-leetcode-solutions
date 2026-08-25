class Solution {
private:
    bool doesIntersect(vector<int>& firstInterval, vector<int>& secondInterval) {
        return firstInterval[0] <= secondInterval[1] && firstInterval[1] >= secondInterval[0];
    }
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int firstListLength = firstList.size();
        int secondListLength = secondList.size();
        vector<vector<int>> intersectedIntervals;

        for(int i = 0, j = 0; i < firstListLength && j < secondListLength; ) {

            vector<int> firstInterval = firstList[i];
            vector<int> secondInterval = secondList[j];
            if(doesIntersect(firstInterval, secondInterval)) {
                int intersectionStart = max(firstInterval[0], secondInterval[0]);
                int intersectionEnd = min(firstInterval[1], secondInterval[1]);
                intersectedIntervals.push_back({intersectionStart, intersectionEnd});
            }

            if(firstInterval[1] < secondInterval[1]) {
                i++;
            }
            else {
                j++;
            }
        }

        return intersectedIntervals;
    }
};
