class LRUCache {
    int capacity;
    list<pair<int, int>> storage;
    unordered_map<int, list<pair<int, int>>::iterator> it;
    
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (it.find(key) == it.end())
            return -1;
        
        int value = it[key]->second;
        put(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if (it.find(key) != it.end())
            storage.erase(it[key]);
        
        storage.push_front({ key, value });
        it[key] = storage.begin();
        
        if (storage.size() > capacity) {
            it.erase(storage.back().first);
            storage.pop_back();
        }
    }
};