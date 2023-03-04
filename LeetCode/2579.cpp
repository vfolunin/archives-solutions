class Solution {
public:
    long long coloredCells(int n) {
        return 2LL * (n - 1) * n + 1;
    }
};