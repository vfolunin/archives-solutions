class MyHashSet {
    vector<int> a;
    
public:
    MyHashSet() : a(1e6 + 1) {}
    
    void add(int key) {
        a[key] = 1;
    }
    
    void remove(int key) {
        a[key] = 0;
    }
    
    bool contains(int key) {
        return a[key];
    }
};