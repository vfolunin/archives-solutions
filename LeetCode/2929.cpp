class Solution {
public:
    long long distributeCandies(int sum, int limit) {
        long long res = 0;
        for (int a = 0; a <= sum && a <= limit; a++) {
            int bl = max(0, sum - limit - a);
            int br = min(limit, sum - a);
            res += max(0, br - bl + 1);
        }
        return res;
    }
};