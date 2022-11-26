class LFUCache {
    int capacity, timer = 0;
    unordered_map<int, int> useCount, time, dict;
    set<tuple<int, int, int>> useCounts;
    
    void use(int key) {
        useCounts.erase({ useCount[key], time[key], key });
        useCount[key]++;
        time[key] = timer++;
        useCounts.insert({ useCount[key], time[key], key });
    }
    
public:
    LFUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (!dict.count(key))
            return -1;
        use(key);
        return dict[key];
    }
    
    void put(int key, int value) {
        if (!capacity)
            return;
        if (dict.size() == capacity && !dict.count(key)) {
            int keyToErase = std::get<2>(*useCounts.begin());
            useCount.erase(keyToErase);
            time.erase(keyToErase);
            dict.erase(keyToErase);
            useCounts.erase(useCounts.begin());
        }
        use(key);
        dict[key] = value;
    }
};