class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, currentGas = 0, startPoint = 0;
        for(int i = 0; i < gas.size(); i++) {
            totalGas += gas[i] - cost[i];
            currentGas += gas[i] - cost[i];
            if(currentGas < 0) {
                currentGas = 0;
                startPoint = i + 1;
            }
        }
        return (totalGas < 0) ? -1 : startPoint;
    }
};