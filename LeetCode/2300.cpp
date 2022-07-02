class Solution {
public:
    vector<int> successfulPairs(vector<int> &a, vector<int> &b, long long minProduct) {
        sort(b.begin(), b.end());
        
        vector<int> res(a.size());
        for (int i = 0; i < a.size(); i++)
            res[i] = b.end() - lower_bound(b.begin(), b.end(), (minProduct + a[i] - 1) / a[i]);
        
        return res;        
    }
};