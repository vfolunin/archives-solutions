class Solution {
public:
    int countSpecialIntegers(vector<int> &a) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < a.size(); i++)
            pos[a[i]].push_back(i);
        
        int res = 0;
        for (auto &[value, pos] : pos)
            res += pos.size() == 3 && pos[2] - pos[1] == pos[1] - pos[0];
        return res;
    }
};