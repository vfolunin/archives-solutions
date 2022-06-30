class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &a, int width, int dist) {
        if (!width || a.size() <= 1)
            return 0;
        width++;
        
        multiset<long long> window(a.begin(), min(a.begin() + width, a.end()));
        for (auto l = window.begin(), r = next(window.begin()); r != window.end(); l++, r++)
            if (*r - *l <= dist)
                return 1;
        
        for (int i = width; i < a.size(); i++) {
            window.erase(window.find(a[i - width]));
            
            auto r = window.upper_bound(a[i]);
            if (r != window.end() && *r - a[i] <= dist ||
                r != window.begin() && a[i] - *prev(r) <= dist)
                return 1;
            
            window.insert(a[i]);
        }
        
        return 0;
    }
};