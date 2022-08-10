class Solution {
public:
    vector<int> advantageCount(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        
        vector<pair<int, int>> bPairs(b.size());
        for (int i = 0; i < b.size(); i++)
            bPairs[i] = { b[i], i };
        sort(bPairs.begin(), bPairs.end());
        
        vector<int> res(a.size());
        for (int ai = 0, bl = 0, br = b.size() - 1; ai < a.size(); ai++) {
            if (a[ai] > bPairs[bl].first) {
                res[bPairs[bl].second] = a[ai];
                bl++;
            } else {
                res[bPairs[br].second] = a[ai];
                br--;
            }
        }
        return res;
    }
};