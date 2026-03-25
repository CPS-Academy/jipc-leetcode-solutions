class Solution {
    bool isPrime(int n){
        // 2, 3, 5, 7, 11, 17
        for(int i = 2; i * i <= n; i++){ // O(sqrt(n))
            // instead of all numbers upto sqrt(n), lets traverse only on primes < n
            if(n % i == 0) return false;
        }
        return true;
    }


    vector<int> generatePrimesUptoNaive(int n){
        vector<int> primes;
        for(int i = 2; i <= n; i++){
            if(isPrime(i)){ // O(sqrt(i))
                primes.push_back(i);
            }
        }
        return primes;
    }
   
    // vector<int> generatePrimesUptoSieve(int n){
    int generatePrimesUptoSieve(int n){
        if(n < 2) return {};
        vector<bool> isPrime(n + 1, true);
        // vector<int> primes;
        // primes.push_back(2);
        int countPrimes = 1;


        for(int i = 3; i <= n; i += 2){ // O(n loglogn)
            if(!isPrime[i]){
                continue;
            }
            // primes.push_back(i);
            countPrimes++;


            if(i > n / i) continue;
            for(int i_mul = i * i; i_mul <= n; i_mul += i){
                isPrime[i_mul] = false;
            }
        }


        // return primes;
        return countPrimes;
    }


public:
    int countPrimes(int n) {
        // return generatePrimesUptoSieve(n - 1).size();
        return generatePrimesUptoSieve(n - 1);
    }
};
