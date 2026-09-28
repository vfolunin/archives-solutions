class Solution {
public:
    int totalDistance(string &s) {
        vector<string> keys = { "qwertyuiop", "asdfghjkl", "zxcvbnm" };
        int y = 1, x = 0, res = 0;
        for (char c : s) {
            for (int ny = 0; ny < keys.size(); ny++) {
                if (int nx = keys[ny].find(c); nx != -1) {
                    res += abs(y - ny) + abs(x - nx);
                    y = ny;
                    x = nx;
                    break;
                }
            }
        }
        return res;
    }
};