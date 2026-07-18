class Solution {
public:
    int jump(vector<int>& nums) {
        int jumpCount = 0;
        int nextJumpRange = 0;
        int i = 0;
        while(nextJumpRange + 1 < nums.size()) { // T.C: O(N) S.C: O(1) / O(N)
            int nextJumpRangeNow = nextJumpRange; // nextJumpRangeNow = max index of green area 
            for(int j = i; j <= nextJumpRangeNow; j++) {
                nextJumpRange = max(nextJumpRange, j + nums[j]); // nextJumpRange = max index of red area 
            }
            jumpCount++;
            i = nextJumpRangeNow + 1;
        }
        return jumpCount;
    }
};