class Solution {
public:
    vector<int> arrayChange(vector<int> &a, vector<vector<int>> &ops) {
        unordered_map<int, int> pos;
        for (int i = 0; i < a.size(); i++)
            pos[a[i]] = i;
        
        for (vector<int> &op : ops) {
            pos[op[1]] = pos[op[0]];
            pos.erase(op[0]);
        }
        
        vector<int> res(pos.size());
        for (auto &[value, index] : pos)
            res[index] = value;
        return res;
    }
};