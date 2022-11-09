class Solution {
public:
    int minSkips(vector<int> &dist, int speed, int timeLimit) {
        vector<vector<int>> time(dist.size() + 1, vector<int>(dist.size(), 1e9));
        time[0][0] = 0;
        
        for (int i = 1; i <= dist.size(); i++) {
            for (int skips = 0; skips < dist.size(); skips++) {
                int withSkip = dist[i - 1] + (skips ? time[i - 1][skips - 1] : 1e9);
                int withoutSkip = dist[i - 1] + (time[i - 1][skips] + speed - 1) / speed * speed;
                time[i][skips] = min(withSkip, withoutSkip);
            }
        }
        
        for (int skips = 0; skips < dist.size(); skips++)
            if (time.back()[skips] <= 1LL * timeLimit * speed)
                return skips;
       
        return -1;
    }
};
