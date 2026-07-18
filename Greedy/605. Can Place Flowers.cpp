class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) { // T.C: O(N), S.C: O(1) / O(N)
        if(n == 0) {
            return true;
        }
        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 1) {
                continue;
            }
            bool isLeftEmpty = i == 0 || flowerbed[i - 1] == 0;
            bool isRightEmpty = i + 1 == flowerbed.size() || flowerbed[i + 1] == 0;
            if(isLeftEmpty && isRightEmpty) {
                n--;
                if(n == 0) {
                    return true;
                }
                flowerbed[i] = 1;
            }
        }
        return false;
    }
};