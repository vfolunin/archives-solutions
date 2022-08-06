class Solution {
    bool can(vector<int> &a, int timeLimit, int speed) {
        long long time = 0;
        for (int value : a)
            time += (value + speed - 1) / speed;
        return time <= timeLimit;
    }
    
public:
    int minEatingSpeed(vector<int> &a, int timeLimit) {
        int l = 0, r = 2e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, timeLimit, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};