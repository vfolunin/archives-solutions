class RandomizedCollection {
    vector<int> values;
    unordered_map<int, unordered_set<int>> pos;
    
public:
    bool insert(int val) {
        bool res = pos[val].empty();
        values.push_back(val);
        pos[val].insert(values.size() - 1);
        return res;
    }
    
    bool remove(int val) {
        if (pos[val].empty())
            return 0;

        if (values.back() != val) {
            int valPos = *pos[val].begin(), lastPos = values.size() - 1, last = values[lastPos];
            pos[last].erase(lastPos);
            pos[last].insert(valPos);
            pos[val].erase(valPos);
            pos[val].insert(lastPos);
            swap(values[valPos], values[lastPos]);
        }
        
        pos[val].erase(values.size() - 1);
        values.pop_back();
        return 1;
    }
    
    int getRandom() {
        return values[rand() % values.size()];
    }
};