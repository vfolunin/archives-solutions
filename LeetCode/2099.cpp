class Solution {
public:
    vector<int> maxSubsequence(vector<int> &a, int k) {
        vector<pair<int, int>> pairs(a.size());
        for (int i = 0; i < pairs.size(); i++)
            pairs[i] = { a[i], i };
        sort(pairs.begin(), pairs.end(), [](auto &x, auto &y) { return x.first > y.first; });
        sort(pairs.begin(), pairs.begin() + k, [](auto &x, auto &y) { return x.second < y.second; });
        
        vector<int> res(k);
        for (int i = 0; i < k; i++)
            res[i] = pairs[i].first;
        return res;
    }
};