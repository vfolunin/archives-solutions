class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &a, int k) {
        vector<int> oneCount(a.size());
        for (int i = 0; i < a.size(); i++)
            oneCount[i] = count(a[i].begin(), a[i].end(), 1);
        
        vector<int> res(a.size());
        iota(res.begin(), res.end(), 0);
        
        sort(res.begin(), res.end(), [&](int a, int b) {
            if (oneCount[a] != oneCount[b])
                return oneCount[a] < oneCount[b];
            return a < b;
        });
        res.resize(k);
        
        return res;
    }
};