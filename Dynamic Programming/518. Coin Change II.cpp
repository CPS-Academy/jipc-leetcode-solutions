class Solution {
private:
    int INVALID = -1;
    vector<vector<int>> ways;
    vector<int> coins;

    int findNumberOfWays(int i_th_coin, int remaining_amount) { // T.C: O(N*AMOUNT) S.C: O(N*AMOUNT)
        if(remaining_amount == 0) return 1;
        if(i_th_coin == coins.size()) return 0;

        int& number_of_ways = ways[i_th_coin][remaining_amount];
        if(number_of_ways != INVALID) {
            return number_of_ways;
        }

        number_of_ways = findNumberOfWays(i_th_coin + 1, remaining_amount);
        if(coins[i_th_coin] <= remaining_amount) {
            number_of_ways += findNumberOfWays(i_th_coin, remaining_amount - coins[i_th_coin]);
        }

        return number_of_ways;
    }

public:
    int change(int amount, vector<int>& coins) {
        this->coins = coins;
        ways.assign(coins.size(), vector<int>(amount + 1, INVALID));
        return findNumberOfWays(0, amount);
    }
};

class Solution {
private:
    int INVALID = -1;
    vector<vector<int>> ways;
    vector<int> coins;

    int findNumberOfWays(int i_th_coin, int remaining_amount) { // T.C: O(N*AMOUNT) S.C: O(N*AMOUNT)
        if(remaining_amount == 0) return 1;
        if(i_th_coin == coins.size()) return 0;

        int& number_of_ways = ways[i_th_coin][remaining_amount];
        if(number_of_ways != INVALID) {
            return number_of_ways;
        }

        number_of_ways = findNumberOfWays(i_th_coin + 1, remaining_amount);
        if(coins[i_th_coin] <= remaining_amount) {
            number_of_ways += findNumberOfWays(i_th_coin, remaining_amount - coins[i_th_coin]);
        }

        return number_of_ways;
    }

public:
    int change(int amount, vector<int>& coins) {
        this->coins = coins;
        ways.assign(coins.size() + 1, vector<int>(amount + 1, 0));
        for(int i_th_coin = coins.size() - 1; i_th_coin >= 0; i_th_coin--) {
            ways[i_th_coin][0] = 1;
            for(int remaining_amount = 1; remaining_amount <= amount; remaining_amount++) {
                int number_of_ways = ways[i_th_coin + 1][remaining_amount];
                if(coins[i_th_coin] <= remaining_amount) {
                    number_of_ways += ways[i_th_coin][remaining_amount - coins[i_th_coin] ];
                }
                ways[i_th_coin][remaining_amount] = number_of_ways;
            }
        }
        return ways[0][amount];
    }
};

class Solution {
private:
    int INVALID = -1;
    vector<int> ways;
public:
    int change(int amount, vector<int>& coins) {
        ways.assign(amount + 1, 0);
        for(int i_th_coin = coins.size() - 1; i_th_coin >= 0; i_th_coin--) {
            ways[0] = 1;
            for(int remaining_amount = 1; remaining_amount <= amount; remaining_amount++) {
                int number_of_ways = ways[remaining_amount];
                if(coins[i_th_coin] <= remaining_amount) {
                    number_of_ways += ways[remaining_amount - coins[i_th_coin] ];
                }
                ways[remaining_amount] = number_of_ways;
            }
        }
        return ways[amount];
    }
};