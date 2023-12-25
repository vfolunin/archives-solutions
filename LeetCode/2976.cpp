class Solution {
public:
    long long minimumCost(string &a, string &b, vector<char> &ca, vector<char> &cb, vector<int> &price) {
        vector<vector<int>> cost(26, vector<int>(26, 1e9));
        for (int i = 0; i < cost.size(); i++)
            cost[i][i] = 0;
        for (int i = 0; i < ca.size(); i++)
            cost[ca[i] - 'a'][cb[i] - 'a'] = min(cost[ca[i] - 'a'][cb[i] - 'a'], price[i]);
        
        for (int v = 0; v < cost.size(); v++)
            for (int a = 0; a < cost.size(); a++)
                for (int b = 0; b < cost.size(); b++)
                    cost[a][b] = min(cost[a][b], cost[a][v] + cost[v][b]);

        long long res = 0;
        for (int i = 0; i < a.size(); i++) {
            if (cost[a[i] - 'a'][b[i] - 'a'] == 1e9)
                return -1;
            res += cost[a[i] - 'a'][b[i] - 'a'];
        }
        return res;
    }
};