class Solution {
public:
    int minSpaceWastedKResizing(vector<int> &a, int k) {
        vector<vector<int>> res(a.size() + 1, vector<int>(k + 1, 1e9));
        res[0][0] = 0;
        
        int maximum = 0, sum = 0;
        for (int i = 1; i <= a.size(); i++) {
            maximum = max(maximum, a[i - 1]);
            sum += a[i - 1];
            res[i][0] = i * maximum - sum;
        }
        
        for (int i = 1; i <= a.size(); i++) {
            for (int ops = 1; ops <= k; ops++) {
                int maximum = 0, sum = 0;
                for (int from = i; from; from--) {
                    maximum = max(maximum, a[from - 1]);
                    sum += a[from - 1];
                    res[i][ops] = min(res[i][ops], res[from - 1][ops - 1] + (i - from + 1) * maximum - sum);
                }
            }
        }
        
        return res[a.size()][k];
    }
};