class Solution {
    long long getDelta(int value, long long time) {
        time /= value;
        long long delta = sqrt(time * 2);
        while (delta * (delta + 1) > time * 2)
            delta--;
        return delta;
    }

    bool can(int height, vector<int> &a, long long time) {
        for (int value : a)
            height -= getDelta(value, time);
        return height <= 0;
    }

public:
    long long minNumberOfSeconds(int height, vector<int> &a) {
        long long l = 0, r = 1;
        while (!can(height, a, r))
            r *= 2;
        
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(height, a, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};