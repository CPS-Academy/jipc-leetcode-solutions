class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> sorted_queries_and_index;
        for(int i = 0; i < queries.size(); i++) {
            sorted_queries_and_index.push_back({queries[i], i});
        }
        sort(sorted_queries_and_index.begin(), sorted_queries_and_index.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        vector<int> shortest_interval_length(queries.size());
        int interval_index = 0;
        for(auto& sorted_query: sorted_queries_and_index) {
            int query = sorted_query.first;
            int index = sorted_query.second;
            // cout << query << " " << index << '\n';
            while(interval_index < intervals.size() && intervals[interval_index][0] <= query) {
                int L = intervals[interval_index][0];
                int R = intervals[interval_index][1];
                min_heap.push({R - L + 1, R}); 
                // cout << R - L + 1 << " " << R << '\n';
                interval_index++;
            }
            // cout << "here\n";
            while(!min_heap.empty() && min_heap.top().second < query) {
                min_heap.pop();
            }
            // cout << "here\n";
            shortest_interval_length[index] = min_heap.empty() ? -1 : min_heap.top().first;
            // cout << shortest_interval_length[index] << '\n';
        }
        return shortest_interval_length;
    }
};
