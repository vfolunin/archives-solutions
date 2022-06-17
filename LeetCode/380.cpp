class RandomizedSet {
    vector<int> values;
    unordered_map<int, int> pos;
    
public:
    bool insert(int val) {
        if (pos.count(val))
            return 0;
        
        values.push_back(val);
        pos[val] = values.size() - 1;
        return 1;
    }
    
    bool remove(int val) {
        if (!pos.count(val))
            return 0;
        
        if (pos[val] != values.size() - 1) {
            pos[values.back()] = pos[val];
            swap(values[pos[val]], values.back());
        }
        
        values.pop_back();
        pos.erase(val);
        return 1;
    }
    
    int getRandom() {
        return values[rand() % values.size()];
    }
};