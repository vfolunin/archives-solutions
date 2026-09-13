class Solution {
public:
    int countSpecialIntegers(vector<int> &a) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < a.size(); i++)
            pos[a[i]].push_back(i);
        
        int res = 0;
        for (auto &[value, pos] : pos) {
            bool ok = pos.size() >= 3;
            for (int i = 1; i + 1 < pos.size() && ok; i++)
                ok &= pos[i + 1] - pos[i] == pos[1] - pos[0];
            res += ok;
        }
        return res;
    }
};