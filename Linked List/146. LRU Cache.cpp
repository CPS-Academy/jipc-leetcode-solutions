class LRUCache {
private:
    int NOT_FOUND = -1;

    int maxCapacity;
    unordered_map<int, int> keyValue;
    list<int> lruCacheList;
    unordered_map<int, list<int>::iterator> addressOf;

    void evict() {
        auto lastKey = lruCacheList.back();
        keyValue.erase(lastKey);
        addressOf.erase(lastKey);
        lruCacheList.pop_back();
    }

public:
    LRUCache(int capacity) {
        maxCapacity = capacity;
        keyValue.clear();
        lruCacheList.clear();
        addressOf.clear();
    }
    
    int get(int key) {
        if(!keyValue.count(key)) {
            return NOT_FOUND;
        }
        auto node = addressOf[key];
        lruCacheList.erase(node);
        lruCacheList.push_front(key);
        addressOf[key] = lruCacheList.begin();
        return keyValue[key];
    }
    
    void put(int key, int value) {
        if(keyValue.size() == maxCapacity && !keyValue.count(key)) {
            evict();
        }
        if(keyValue.count(key)) {
            lruCacheList.erase(addressOf[key]);
        }
        lruCacheList.push_front(key);
        addressOf[key] = lruCacheList.begin();
        keyValue[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
