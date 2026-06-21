class Solution {
public:
    int maxDistance(string &s) {
        int y = 0, x = 0, add = 0;
        for (char c : s) {
            y += c == 'U';
            y -= c == 'D';
            x += c == 'R';
            x -= c == 'L';
            add += c == '_';
        }
        return abs(y) + abs(x) + add;
    }
};