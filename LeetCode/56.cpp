class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &segments) {
        sort(segments.begin(), segments.end());
        
        vector<vector<int>> res;
        for (vector<int> &segment : segments) {
            if (res.empty() || res.back()[1] < segment[0])
                res.push_back(segment);
            else
                res.back()[1] = max(res.back()[1], segment[1]);
        }
        
        return res;
    }
};