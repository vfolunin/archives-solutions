class Solution {
public:
    int maxDepthBST(vector<int> &a) {
        map<int, int> depth = { { 0, 0 }, { a.size(), 0 } };
        int res = 0;

        for (int value : a) {
            auto r = depth.lower_bound(value);
            auto l = prev(r);
            depth[value] = max(l->second, r->second) + 1;
            res = max(res, depth[value]);
        }
        
        return res;
    }
};