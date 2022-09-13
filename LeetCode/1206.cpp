class Skiplist {
    multiset<int> values;
    
public:    
    bool search(int value) {
        return values.find(value) != values.end();
    }
    
    void add(int value) {
        values.insert(value);
    }
    
    bool erase(int value) {
        if (auto it = values.find(value); it != values.end()) {
            values.erase(it);
            return 1;
        }
        return 0;
    }
};