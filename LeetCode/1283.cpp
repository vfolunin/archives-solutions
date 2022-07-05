class Solution {
    bool can(vector<int> &a, int d, int threshold) {
        long long sum = 0;
        for (int value : a)
            sum += (value + d - 1) / d;
        return sum <= threshold;
    }
    
public:
    int smallestDivisor(vector<int> &a, int threshold) {
        int l = 0, r = 1e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, m, threshold))
                r = m;
            else
                l = m;
        }
        return r;
    }
};