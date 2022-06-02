class KthLargest {
    int size;
    multiset<int> s;
    
public:
    KthLargest(int k, vector<int> &a) : size(k) {
        for (int value : a)
            add(value);
    }
    
    int add(int value) {
        s.insert(value);
        if (s.size() > size)
            s.erase(s.begin());
        return *s.begin();
    }
};