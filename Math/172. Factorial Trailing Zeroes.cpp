class Solution {
public:
    int trailingZeroes(int n) {
        int k = 5;
        int ans = 0;
        while(k <= n){ // time O(logn)
            ans += (n / k);
            k *= 5;
        }
        return ans;
    }
};
