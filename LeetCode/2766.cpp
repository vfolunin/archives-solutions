class Solution {
public:
    vector<int> relocateMarbles(vector<int> &pos, vector<int> &from, vector<int> &to) {
        map<int, int> count;
        for (int p : pos)
            count[p]++;
        
        for (int i = 0; i < from.size(); i++) {
            if (from[i] != to[i]) {
                count[to[i]] += count[from[i]];
                count.erase(from[i]);
            }
        }
        
        vector<int> res;
        for (auto &[pos, _] : count)
            res.push_back(pos);
        return res;
    }
};