class Solution {
public:
    int minQueenMoves(vector<int> &a, vector<int> &b) {
        if (a == b)
            return 0;
        else if (a[0] == b[0] || a[1] == b[1] || abs(a[0] - b[0]) == abs(a[1] - b[1]))
            return 1;
        else
            return 2;
    }
};