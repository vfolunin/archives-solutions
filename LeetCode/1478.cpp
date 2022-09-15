class Solution {
public:
    int minDistance(vector<int> &a, int boxCount) {
        sort(a.begin(), a.end());
        
        vector<vector<int>> cost(a.size(), vector<int>(a.size(), 1e9));
        for (int l = 0; l < a.size(); l++) {
            for (int r = l; r < a.size(); r++) {
                int m = l + (r - l) / 2;
                cost[l][r] = 0;
                for (int i = l; i <= r; i++)
                    cost[l][r] += abs(a[i] - a[m]);
            }
        }
        
        vector<vector<int>> res(a.size(), vector<int>(boxCount + 1, 1e9));
        for (int to = 0; to < a.size(); to++) {
            res[to][1] = cost[0][to];
            for (int boxes = 2; boxes <= boxCount && boxes <= to + 1; boxes++)
                for (int from = 1; from <= to; from++)
                    res[to][boxes] = min(res[to][boxes], res[from - 1][boxes - 1] + cost[from][to]);
        }
        
        return res[a.size() - 1][boxCount];
    }
};