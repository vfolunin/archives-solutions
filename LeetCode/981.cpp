class TimeMap {
    unordered_map<string, map<int, string>> storage;
    
public:
    void set(string key, string value, int time) {
        storage[key][time] = value;
    }
    
    string get(string key, int time) {
        if (!storage.count(key))
            return "";
        
        auto it = storage[key].upper_bound(time);
        if (it == storage[key].begin())
            return "";
        
        return prev(it)->second;
    }
};