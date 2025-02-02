class Solution {
public:
    int maxDistance(string &s, int limit) {
        int dy = 0, dx = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            dy -= s[i] == 'N';
            dy += s[i] == 'S';
            dx -= s[i] == 'W';
            dx += s[i] == 'E';
            res = max(res, min(abs(dy) + abs(dx) + 2 * limit, i + 1));
        }
        return res;
    }
};