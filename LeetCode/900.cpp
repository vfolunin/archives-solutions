class RLEIterator {
    vector<int> a;
    int index = 0;
    
public:
    RLEIterator(vector<int> &a) : a(a) {}
    
    int next(int n) {
        while (index < a.size() && n > a[index]) {
            n -= a[index];
            index += 2;
        }
        
        if (index == a.size())
            return -1;
        
        a[index] -= n;
        return a[index + 1];
    }
};