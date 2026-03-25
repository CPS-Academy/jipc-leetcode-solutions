class Solution {
    int mod = 2000000011;


    int fastExponent(int a, int n){
        if(n == 0) return 1;
        if(n == 1) return a;
       
        long long int mult = a;
        long long int ans = 1;
        while(n > 0){    
            if(n & 1){
                ans = ans * mult % mod;
            }
           
            mult = mult * mult % mod;
            n >>= 1;
        }
       
        return ans;
    }


    int modInverse(int a){
        return fastExponent(a, mod - 2);
    }


    int nCr[102][102];


    int C_2D(int n, int r){
        if(n < 0 || r < 0) return 0;
        if(r == 0) return 1; // time O(n^2), space O(n^2)
        if(n < r) return 0;
        if(nCr[n][r] != -1) return nCr[n][r];
   
        int ans = C_2D(n - 1, r - 1) + C_2D(n - 1, r) % mod;
        nCr[n][r] = ans;
        return ans;
    }


    int C_r(int n, int r){ // time O(r), space constant
        long long int ans = 1;
        // 1000 C 3
        int num = n, denom = 1;
        for(int i = 1; i <= r; i++){
            ans = ans * num % mod;
            num--;
            ans = ans * modInverse(denom) % mod;
            denom++;
        }
        return ans;
    }


    long long int fact[102];


    int C_fact(int n, int r) // time O(1), space O(n)
    {
        return fact[n] * modInverse(fact[n - r]) % mod * modInverse(fact[r]) % mod;
    }


public:
    int uniquePaths(int m, int n) {
        fact[0] = 1;
        fact[1] = 1;
        for(int i = 2; i < 102; i++){
            fact[i] = fact[i - 1] * i % mod;
        }


        for(int i = 0; i < 102; i++){
            for(int j = 0; j < 102; j++){
                nCr[i][j] = -1;
            }
        }


        return C_2D(m + n - 2, n - 1);
    }
};
