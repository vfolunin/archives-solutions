class Solution {
    bool can(vector<int> &period, int tripNeeded, long long time) {
        long long tripCount = 0;
        for (int p : period)
            tripCount += time / p;
        return tripCount >= tripNeeded;
    }
    
public:
    long long minimumTime(vector<int> &period, int tripNeeded) {
        long long l = 0, r = 1;
        while (!can(period, tripNeeded, r))
            r *= 2;
        
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(period, tripNeeded, m))
                r = m;
            else
                l = m;
        }
        
        return r;
    }
};