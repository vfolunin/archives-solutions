class Solution {
    bool can(int n, vector<int> &a, long long time) {
        long long sum = 0;
        for (int value : a)
            sum += min<long long>(value, time);
        return sum >= n * time;
    }
    
public:
    long long maxRunTime(int n, vector<int> &a) {
        long long l = 0, r = 1;
        while (can(n, a, r))
            r *= 2;
        
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(n, a, m))
                l = m;
            else
                r = m;
        }
        
        return l;
    }
};