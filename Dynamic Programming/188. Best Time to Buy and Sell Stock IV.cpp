class Solution {
private:
    int INVALID = -1;
    int maxSequence;
    vector<vector<int>> dp;
    vector<vector<bool>> isVisited;
    int getMaxProfit(int day, int sequence, vector<int>& prices) { // T.C: O(K*D) S.C: O(K*D)
        if(sequence > maxSequence || (day == prices.size() && (sequence&1))) {
            return INT_MIN/2;
        }
        if(day == prices.size()) {
            return 0;
        }

        if(isVisited[day][sequence]) {
            return dp[day][sequence];
        }

        int doNothing = getMaxProfit(day + 1, sequence, prices);
        int state = ((sequence&1) == 0) ? -1 : 1;
        int buyOrSell = state*prices[day] + getMaxProfit(day + 1, sequence + 1, prices);

        isVisited[day][sequence] = true;
        return dp[day][sequence] = max(doNothing, buyOrSell);
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        isVisited.assign(prices.size(), vector<bool>(k + k + 1, false));
        dp.assign(prices.size(), vector<int>(k + k + 1, INVALID));
        maxSequence = k + k;
        return getMaxProfit(0, 0, prices);
    }
};