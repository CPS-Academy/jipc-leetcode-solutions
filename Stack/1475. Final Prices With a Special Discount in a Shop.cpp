//Approach 1 - Brute Force O(n²):
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> discountedPrices;
        for(int i = 0; i < prices.size(); i++) {
            int discount = 0;
            for(int j = i + 1; j < prices.size(); j++) {
                if(prices[j] <= prices[i]) {
                    discount = prices[j];
                    break;
                }
            }
            discountedPrices.push_back(prices[i] - discount);
        }
        return discountedPrices;
    }
};

//Approach 2 - Monotonic Stack O(n):
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> discountedPrices;
        stack<int> discountPriceStack;

        for(int i = prices.size() - 1; i >= 0; i--) {
            int price = prices[i];
            while(!discountPriceStack.empty() && price < discountPriceStack.top()) {
                discountPriceStack.pop();
            }
            int discountedPrice = discountPriceStack.empty() ? price : price - discountPriceStack.top();
            discountedPrices.push_back(discountedPrice);
            discountPriceStack.push(price);
        }

        reverse(discountedPrices.begin(), discountedPrices.end());
        return discountedPrices;
    }
};
