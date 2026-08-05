class Solution {
private:
    const int INVALID = -1;
    vector<int> prices;
    vector<vector<int>> dp;
    int tradeDays;

    int findMaxProfit(int currentDay, int isBuyingState) { // T.C: O(N) S.C: O(N)
        if(currentDay >= tradeDays) {
            return 0;
        }
        int& store = dp[currentDay][isBuyingState];
        if(store != INVALID) {
            return store;
        }

        int profitBySkipping = findMaxProfit(currentDay + 1, isBuyingState);
        if(isBuyingState) {
            return store = max(-prices[currentDay] + findMaxProfit(currentDay + 1, 0), profitBySkipping);
        }
        return store = max(prices[currentDay] + findMaxProfit(currentDay + 2, 1), profitBySkipping);
    }

public:
    int maxProfit(vector<int>& prices) {
        tradeDays = prices.size();
        dp.assign(3, vector<int>(2, 0));
        
        for(int i = tradeDays - 1; i >= 0; i--) {
            int currentDay = i%3;
            int nextDay = (currentDay + 1)%3;
            int nextOfNextDay = (nextDay + 1)%3;
            dp[currentDay][0] = max(prices[i] + dp[nextOfNextDay][1], dp[nextDay][0]); // selling state
            dp[currentDay][1] = max(-prices[i] + dp[nextDay][0], dp[nextDay][1]); // buying state
        }
        return dp[0][1];
    }
};


class Solution {
private:
    const int INVALID = -1;
    vector<int> prices;
    vector<vector<int>> dp;
    int tradeDays;

    int findMaxProfit(int currentDay, int isBuyingState) {
        if(currentDay >= tradeDays) {
            return 0;
        }
        int& store = dp[currentDay][isBuyingState];
        if(store != INVALID) {
            return store;
        }

        int profitBySkipping = findMaxProfit(currentDay + 1, isBuyingState);
        if(isBuyingState) {
            return store = max(-prices[currentDay] + findMaxProfit(currentDay + 1, 0), profitBySkipping);
        }
        return store = max(prices[currentDay] + findMaxProfit(currentDay + 2, 1), profitBySkipping);
    }

public:
    int maxProfit(vector<int>& prices) {
        tradeDays = prices.size();
        dp.assign(tradeDays, vector<int>(2, INVALID));
        this->prices = prices;
        return findMaxProfit(0, 1);
    }
};