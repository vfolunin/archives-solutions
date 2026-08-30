class Solution {
public:
    int minBishopMoves(vector<int> &a, vector<int> &b) {
        if ((a[0] + a[1]) % 2 != (b[0] + b[1]) % 2)
            return -1;
        else if (a[0] + a[1] == b[0] + b[1] || a[0] - a[1] == b[0] - b[1])
            return 1;
        else
            return 2;
    }
};