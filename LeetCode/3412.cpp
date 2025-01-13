class Solution {
public:
    long long calculateScore(string &s) {
        vector<vector<int>> pos(26);
        long long res = 0;

        for (int i = 0; i < s.size(); i++) {
            char a = s[i] - 'a', b = 25 - a;
            if (pos[b].empty()) {
                pos[a].push_back(i);
            } else {
                res += i - pos[b].back();
                pos[b].pop_back();
            }
        }

        return res;
    }
};