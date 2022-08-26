class Solution {
    bool can(vector<int> &dist, double limit, int speed) {
        int time = 0;
        for (int i = 0; i + 1 < dist.size(); i++)
            time += (dist[i] + speed - 1) / speed;
        return time + (double)dist.back() / speed <= limit;
    }
    
public:
    int minSpeedOnTime(vector<int> &dist, double limit) {
        int l = 0, r = 1e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(dist, limit, m))
                r = m;
            else
                l = m;
        }
        return r != 1e9 ? r : -1;
    }
};