class Solution {
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        vector<int> periods = { 1, 7, 30 };
        vector<int> res(days.size(), 1e9);
        
        for (int i = 0; i < days.size(); i++) {
            for (int j = 0; j < costs.size(); j++) {
                int from = upper_bound(days.begin(), days.end(), days[i] - periods[j]) - days.begin();
                res[i] = min(res[i], costs[j] + (from ? res[from - 1] : 0));
            }
        }
        
        return res.back();
    }
};