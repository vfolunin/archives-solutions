class Solution {
public:
    int calculateTime(string &keyboard, string &word) {
        int pos = 0, res = 0;
        for (char c : word) {
            int nextPos = keyboard.find(c);
            res += abs(pos - nextPos);
            pos = nextPos;
        }
        return res;
    }
};