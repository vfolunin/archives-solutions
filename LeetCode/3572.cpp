class Solution {
public:
    int maxSumDistinctTriplet(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> maxB;
        for (int i = 0; i < a.size(); i++)
            maxB[a[i]] = max(maxB[a[i]], b[i]);
        
        vector<int> res;
        for (auto &[a, b] : maxB)
            res.push_back(b);
        
        if (res.size() >= 3) {
            sort(res.rbegin(), res.rend());
            return res[0] + res[1] + res[2];
        } else {
            return -1;
        }
    }
};