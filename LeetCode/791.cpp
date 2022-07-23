class Solution {
public:
    string customSortString(string &order, string &s) {
        vector<int> pos(26, 1e9);
        for (int i = 0; i < order.size(); i++)
            pos[order[i] - 'a'] = i;
        
        sort(s.begin(), s.end(), [&](char a, char b) {
            return pos[a - 'a'] < pos[b - 'a'];
        });
        return s;
    }
};