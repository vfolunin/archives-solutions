class Solution {
public:
    long long maxEarnings(vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> order(meetings.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return meetings[a][1] < meetings[b][1];
        });

        vector<long long> maxProfit(meetings.size());
        long long maxDelta = -1e18;
        
        for (int l = 0, r = 0; r < meetings.size(); r++) {
            while (l < meetings.size() && meetings[order[l]][1] <= meetings[r][0]) {
                maxDelta = max(maxDelta, maxProfit[order[l]] - meetings[order[l]][1]);
                l++;
            }

            maxProfit[r] = max(meetings[r][0] + maxDelta, 0LL) + meetings[r][2];
        }

        return *max_element(maxProfit.begin(), maxProfit.end());
    }
};