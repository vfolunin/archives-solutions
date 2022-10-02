class Solution {
public:
    int maxSum(vector<vector<int>> &a) {
        int res = 0;
        
        for (int y = 0; y + 3 <= a.size(); y++) {
            for (int x = 0; x + 3 <= a[0].size(); x++) {
                int sum = -a[y + 1][x] - a[y + 1][x + 2];
                
                for (int dy = 0; dy < 3; dy++)
                    for (int dx = 0; dx < 3; dx++)
                        sum += a[y + dy][x + dx];
                
                res = max(res, sum);
            }
        }
        
        return res;
    }
};