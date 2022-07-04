class Solution {
    bool can(vector<int> &a, long long k, long long size) {
        long long count = 0;
        for (int value : a)
            count += value / size;
        return count >= k;
    }
    
public:
    int maximumCandies(vector<int> &a, long long k) {
        int l = 0, r = 1e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, k, m))
                l = m;
            else
                r = m;
        }
        return l;
    }
};