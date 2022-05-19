class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s = { 1 };
        
        for (int i = 1; i < n; i++) {
            long long value = *s.begin();
            s.erase(s.begin());
            
            for (int factor : { 2, 3, 5 }) {
                long long newValue = value * factor;
                if (s.size() < 1700 || newValue < *--end(s))
                    s.insert(newValue);
            }
        }
        
        return *s.begin();
    }
};