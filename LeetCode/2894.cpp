class Solution {
public:
    int differenceOfSums(int n, int d) {
        int a = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            if (i % d)
                a += i;
            else
                b += i;
        }
        return a - b;
    }
};