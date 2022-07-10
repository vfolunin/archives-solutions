class Solution {
public:
    vector<int> rearrangeArray(vector<int> &a) {
        sort(a.begin(), a.end());
        
        vector<int> res(a.size());
        int ai = 0;
        
        for (int ri = 0; ri < res.size(); ri += 2)
            res[ri] = a[ai++];
        for (int ri = 1; ri < res.size(); ri += 2)
            res[ri] = a[ai++];
        
        return res;
    }
};