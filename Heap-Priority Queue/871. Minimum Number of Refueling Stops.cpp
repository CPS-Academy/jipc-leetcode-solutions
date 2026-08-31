class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target, 0});
        priority_queue<int> maxHeap;
        int current_fuel = startFuel;
        int min_refueling = 0;
        int previous_position = 0;
        for(auto& station: stations) {
            int position = station[0];
            int fuel = station[1];
            current_fuel -= position - previous_position;
            while(!maxHeap.empty() && current_fuel < 0) {
                current_fuel += maxHeap.top();
                maxHeap.pop();
                min_refueling++;
            }

            if(current_fuel < 0) {
                return -1;
            }
            maxHeap.push(fuel);
            previous_position = position;
        }
        return min_refueling;
    }
};
