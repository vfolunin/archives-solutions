class Solution {
public:
    bool find132pattern(vector<int> &a) {
        vector<int> prefixMin = a;
        for (int i = 1; i < prefixMin.size(); i++)
            prefixMin[i] = min(prefixMin[i], prefixMin[i - 1]);
        
        set<int> suffix = { a.back() };
        
        for (int i = (int)a.size() - 2; i > 0; i--) {
            if (auto it = suffix.lower_bound(a[i]); it != suffix.begin() && prefixMin[i - 1] < *--it)
                return 1;
            suffix.insert(a[i]);
        }
        
        return 0;
    }
};