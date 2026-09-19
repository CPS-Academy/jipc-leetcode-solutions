// LeetCode 981. Time Based Key-Value Store
// https://leetcode.com/problems/time-based-key-value-store/
// Each key stores (timestamp, value) pairs in increasing timestamp order;
// binary search for the largest timestamp <= the query timestamp.
class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> kv_ds;
    TimeMap()
    {
        // Already initialized
    }

    void set(string key, string value, int timestamp)
    {
        kv_ds[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (!kv_ds.count(key))
            return "";

        auto &v = kv_ds[key];

        int low = 0, high = v.size() - 1;

        string ans = "";

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (v[mid].first <= timestamp)
            {
                ans = v[mid].second;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */