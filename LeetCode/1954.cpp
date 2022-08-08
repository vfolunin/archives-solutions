class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long l = 0, r = 1e5;
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (2 * m * (m + 1) * (2 * m + 1) < neededApples)
                l = m;
            else
                r = m;
        }
        return r * 8;
    }
};