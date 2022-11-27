class Solution {
    int sum(int l, int r) {
        return (l + r) * (r - l + 1) / 2;
    }
    
public:
    int pivotInteger(int n) {
        for (int i = 1; i <= n; i++)
            if (sum(1, i) == sum(i, n))
                return i;
        return -1;
    }
};