class Solution {
public:
    bool checkDistances(string &s, vector<int> &dist) {
        vector<int> pos(26, -1);
        for (int i = 0; i < s.size(); i++) {
            if (pos[s[i] - 'a'] == -1)
                pos[s[i] - 'a'] = i;
            else if (i - pos[s[i] - 'a'] - 1 != dist[s[i] - 'a'])
                return 0;
        }
        return 1;
    }
};