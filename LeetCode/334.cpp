class Solution {
public:
    bool increasingTriplet(vector<int> &a) {
        multiset<int> l, r(a.begin(), a.end());
        
        for (int value : a) {
            r.erase(r.find(value));
            
            if (!l.empty() && *l.begin() < value &&
                !r.empty() && value < *--r.end())
                return 1;
            
            l.insert(value);
        }
        
        return 0;
    }
};