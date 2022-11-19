class Solution {
public:
    int maxValue(vector<vector<int>> &events, int limit) {
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        
        vector<vector<int>> bonus(size(events) + 1, vector<int>(limit + 1));
        
        for (int i = 1; i <= events.size(); i++) {
            int j = lower_bound(events.begin(), events.end(), events[i - 1], [](auto& a, auto& b) {
                return a[1] < b[0];
            }) - events.begin();
            
            for (int k = 1; k <= limit; k++)
                bonus[i][k] = max(bonus[i - 1][k], bonus[j][k - 1] + events[i - 1][2]);
        }
        
        return bonus[events.size()][limit];
    }
};