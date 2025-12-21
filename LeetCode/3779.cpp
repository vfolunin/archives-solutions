class Solution {
public:
    int minOperations(vector<int> &a) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < a.size(); i++)
            pos[a[i]].push_back(i);
        
        int res = 0;
        for (auto &[_, pos] : pos)
            if (pos.size() >= 2)
                res = max(res, pos[pos.size() - 2] / 3 + 1);
        return res;
    }
};