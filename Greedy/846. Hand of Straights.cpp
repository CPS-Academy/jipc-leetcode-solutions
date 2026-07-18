class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) { // T.C: O(NlogN) S.C: O(N)
        int handSize = hand.size();
        if(handSize%groupSize != 0) {
            return false;
        }

        unordered_map<int, int> cardFrequency;
        for(auto& card: hand) { // O(N)
            cardFrequency[card]++;
        }

        for(auto& card: hand) {
            int startCard = card;
            while(cardFrequency[startCard - 1]) {
                startCard--;
            }
            while(startCard <= card) {
                while(cardFrequency[startCard] > 0) {
                    for(auto nextCard = startCard; nextCard < startCard + groupSize; nextCard++) {
                        if(!cardFrequency.count(nextCard)) {
                            return false;
                        }
                        cardFrequency[nextCard]--;
                        if(cardFrequency[nextCard] == 0) {
                            cardFrequency.erase(nextCard);
                        }
                    }
                }
                startCard++;
            }
        }
        return true;
    }
};