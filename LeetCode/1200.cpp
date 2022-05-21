class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &a) {
        sort(a.begin(), a.end());
        
        int minDiff = 1e9;
        vector<vector<int>> res;
        
        for (int i = 1; i < a.size(); i++) {
            int diff = a[i] - a[i - 1];
            if (minDiff > diff) {
                minDiff = diff;
                res = { { a[i - 1], a[i] } };
            } else if (minDiff == diff) {
                res.push_back({ a[i - 1], a[i] });
            }
        }
        
        return res;
    }
};