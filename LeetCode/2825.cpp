class Solution {
public:
    bool canMakeSubsequence(string &a, string &b) {
        int bi = 0;
        for (int ai = 0; ai < a.size() && bi < b.size(); ai++)
            bi += a[ai] == b[bi] || (a[ai] - 'a' + 1) % 26 + 'a' == b[bi];

        return bi == b.size();
    }
};