class Solution {
public:
    int countValidPrefixes(string &s) {
        vector<int> count(2);
        int res = 0;

        for (char c : s) {
            count[c - '0']++;
            res += abs(count[0] - count[1]) <= 1;
        }

        return res;
    }
};