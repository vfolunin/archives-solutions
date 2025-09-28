class Solution {
public:
    int distinctPoints(string &s, int width) {
        int y = 0, x = 0;
        vector<pair<int, int>> p(1, { y, x });
        set<pair<int, int>> deltas;

        for (int i = 0; i < s.size(); i++) {
            y -= s[i] == 'U';
            y += s[i] == 'D';
            x -= s[i] == 'L';
            x += s[i] == 'R';

            if (i >= width - 1) {
                int dy = y - p[1 + i - width].first;
                int dx = x - p[1 + i - width].second;
                deltas.insert({ dy, dx });
            }

            p.push_back({ y, x });
        }

        return deltas.size();
    }
};