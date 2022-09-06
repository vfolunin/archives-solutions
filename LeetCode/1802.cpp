class Solution {
    long long sum(long long from, long long count) {
        long long decreasingCount = min(from, count);
        long long res = (from + from - decreasingCount + 1) * decreasingCount / 2;
        res += count - decreasingCount;
        return res;
    }
    
public:
    int maxValue(int size, int index, int sumLimit) {
        long long l = 1, r = 2e9;
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;            
            if (sum(m, index + 1) + sum(m - 1, size - 1 - index) <= sumLimit)
                l = m;
            else
                r = m;
        }
        return l;
    }
};