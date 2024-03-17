class Solution {
public:
    long long countSubstrings(string &s, char targetC) {
        int count = 0;
        long long res = 0;

        for (char c : s) {
            if (c == targetC) {
                count++;
                res += count;
            }
        }

        return res;
    }
};