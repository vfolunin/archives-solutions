class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n - k - 1);
        iota(res.begin(), res.end(), 1);
        
        for (int i = 0; i <= k; i++)
            res.push_back(i % 2 ? n - i / 2 : n - k + i / 2);
        
        return res;
    }
};