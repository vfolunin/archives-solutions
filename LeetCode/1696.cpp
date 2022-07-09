class Solution {
public:
    int maxResult(vector<int> &a, int k) {
        vector<int> res(a.size(), -1e9);
        res[0] = a[0];
        
        multiset<int> window = { res[0] };
        for (int i = 1; i < a.size(); i++) {
            res[i] = a[i] + *--window.end();
            
            window.insert(res[i]);
            if (i >= k)
                window.erase(window.find(res[i - k]));
        }
        
        return res.back();
    }
};