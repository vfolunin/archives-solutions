class Solution {
public:
    int minCost(string &colors, vector<int> &price) {
        vector<vector<int>> cost(colors.size() + 1, vector<int>(26, 1e9));
        fill(cost[0].begin(), cost[0].end(), 0);
        
        for (int i = 1; i <= colors.size(); i++) {
            int color = colors[i - 1] - 'a';
            for (int last = 0; last < 26; last++)
                if (last != color)
                    cost[i][colors[i - 1] - 'a'] = min(cost[i][colors[i - 1] - 'a'], cost[i - 1][last]);

            for (int last = 0; last < 26; last++)
                cost[i][last] = min(cost[i][last], cost[i - 1][last] + price[i - 1]);
        }

        return *min_element(cost.back().begin(), cost.back().end());
    }
};