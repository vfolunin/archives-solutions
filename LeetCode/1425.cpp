class Solution {
public:
    int constrainedSubsetSum(vector<int> &a, int k) {
        vector<int> res(a.size());
        res[0] = a[0];
        multiset<int> window = { res[0] };
        
        for (int i = 1; i < a.size(); i++) {
            if (i > k)
                window.erase(window.find(res[i - k - 1]));
            
            res[i] = max(a[i], a[i] + *window.rbegin());
            
            window.insert(res[i]);
        }
        
        return *max_element(res.begin(), res.end());
    }
};