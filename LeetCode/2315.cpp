class Solution {
public:
    int countAsterisks(string s) {
        int in = 0, res = 0;
        for (char c : s) {
            if (c == '|')
                in ^= 1;
            else if (c == '*')
                res += !in;
        }
        return res;
    }
};