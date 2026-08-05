class Solution {
public:
    int maxProfit(vector<int>& prices) { // T.C: O(N) S.C: O(1) / O(N)
        int minCostBuyTransaction1 = INT_MAX;
        int maxProfitTransaction1 = 0;
        int maxProfit_transaction1AndBuyOfTransaction2 = INT_MIN/2;
        int maxProfit_overAll = 0;
        for(auto& price: prices) {
            minCostBuyTransaction1 = min(minCostBuyTransaction1, price);
            maxProfitTransaction1 = max(maxProfitTransaction1, price - minCostBuyTransaction1);

            maxProfit_transaction1AndBuyOfTransaction2 = max(maxProfit_transaction1AndBuyOfTransaction2, maxProfitTransaction1 - price);
            maxProfit_overAll = max(maxProfit_overAll, maxProfit_transaction1AndBuyOfTransaction2 + price);
        }
        return max(maxProfitTransaction1, maxProfit_overAll);
    }
};