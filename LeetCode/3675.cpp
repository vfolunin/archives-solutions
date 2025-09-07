class Solution {
public:
    int minOperations(string &s) {
        int res = 0;
        for (char c : s)
            res = max(res, ('a' - c + 26) % 26);
        return res;
    }
};