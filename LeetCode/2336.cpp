class SmallestInfiniteSet {
    unordered_set<int> absent;
    int smallest = 1;
    
public:    
    int popSmallest() {
        int res = smallest;
        
        absent.insert(smallest);
        while (absent.count(smallest))
            smallest++;
        
        return res;
    }
    
    void addBack(int value) {
        absent.erase(value);
        smallest = min(smallest, value);
    }
};