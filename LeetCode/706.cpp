class MyHashMap {
    vector<int> a;
    
public:
    MyHashMap() : a(1e6 + 1, -1) {}
    
    void put(int key, int value) {
        a[key] = value;
    }
    
    int get(int key) {
        return a[key];
    }
    
    void remove(int key) {
        a[key] = -1;
    }
};