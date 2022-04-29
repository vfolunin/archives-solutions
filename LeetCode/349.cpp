class Solution {
public:
    vector<int> intersection(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> res;
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};