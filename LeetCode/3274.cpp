class Solution {
public:
    bool checkTwoChessboards(string &a, string &b) {
        return (a[0] + a[1]) % 2 == (b[0] + b[1]) % 2;
    }
};