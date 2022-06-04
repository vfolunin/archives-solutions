class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int> &a, int h, int w) {
        if (a.size() != h * w)
            return {};
        
        vector<vector<int>> res;
        for (int l = 0, r = w; r <= a.size(); l += w, r += w)
            res.push_back({ a.begin() + l, a.begin() + r });
        return res;
    }
};