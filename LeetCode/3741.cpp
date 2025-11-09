class Solution {
public:
    int minimumDistance(vector<int> &a) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < a.size(); i++)
            pos[a[i]].push_back(i);
        
        int res = 1e9;
        for (auto &[value, pos] : pos)
            for (int i = 0; i + 2 < pos.size(); i++)
                res = min(res, 2 * (pos[i + 2] - pos[i]));
        return res != 1e9 ? res : -1;
    }
};