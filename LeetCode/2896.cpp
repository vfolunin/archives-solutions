class Solution {
public:
    int minOperations(string &a, string &b, int price) {
        vector<int> diff;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i])
                diff.push_back(i);
        
        if (diff.size() % 2)
            return -1;
        
        if (diff.empty())
            return 0;

        vector<vector<int>> cost(diff.size(), vector<int>(diff.size(), 1e9));
        for (int i = 0; i + 1 < diff.size(); i++) 
            cost[i][i + 1] = min(diff[i + 1] - diff[i], price);

        for (int len = 4; len <= diff.size(); len += 2)
            for (int l = 0, r = len - 1; r < diff.size(); l++, r++)
                cost[l][r] = min({ cost[l][l + 1] + cost[l + 2][r], cost[l][r - 2] + cost[r - 1][r], cost[l + 1][r - 1] + price });

        return cost[0][diff.size() - 1] != 1e9 ? cost[0][diff.size() - 1] : -1;
    }
};