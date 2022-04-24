class Solution {
public:
    int maxCount(int h, int w, vector<vector<int>> &ops) {
        for (vector<int> &op : ops) {
            h = min(h, op[0]);
            w = min(w, op[1]);
        }
        return h * w;
    }
};