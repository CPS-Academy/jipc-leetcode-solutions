class Solution {
private:
    int getSmallestValue(priority_queue<int, vector<int>, greater<int>>& min_heap) { // O(logN)
        int smallest_value = min_heap.top();
        min_heap.pop();
        return smallest_value;
    }
public:
    int connectSticks(vector<int>& sticks) { // O(NlogN)
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(auto& stick: sticks) {
            min_heap.push(stick);
        }

        int total_cost = 0;
        while(min_heap.size() > 1) { // O(N)
            int smallest_value = getSmallestValue(min_heap);
            int second_smallest_value = getSmallestValue(min_heap);

            int lenth_after_connecting = smallest_value + second_smallest_value;
            total_cost += lenth_after_connecting;
            min_heap.push(lenth_after_connecting);
        }
        return total_cost;
    }
};




class Solution {
private:
    int getSmallestValue(vector<int>& sticks) {
        int smallest_value = sticks.back();
        sticks.pop_back();
        return smallest_value;
    }
public:
    int connectSticks(vector<int>& sticks) {
        int total_cost = 0;
        while(sticks.size() > 1) {
            sort(sticks.begin(), sticks.end(), greater<int>());

            int smallest_value = getSmallestValue(sticks);
            int second_smallest_value = getSmallestValue(sticks);

            int lenth_after_connecting = smallest_value + second_smallest_value;
            total_cost += lenth_after_connecting;
            sticks.push_back(lenth_after_connecting);
        }
        return total_cost;
    }
};
