class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;
        while(low <= high) {
            int mid = low + (high - low)/2;
            long long square = (long long)mid * (long long)mid;
            if(square == num)return true;
            else if(square < num)low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};
