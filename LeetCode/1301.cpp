class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string> &a) {
        a[0][0] = '0';
        
        const long long MOD = 1e9 + 7;
        
        vector<vector<long long>> sum(a.size(), vector<long long>(a.size()));
        vector<vector<long long>> ways(a.size(), vector<long long>(a.size()));
        
        sum.back().back() = 0;
        ways.back().back() = 1;
        
        for (int y = a.size() - 1; y >= 0; y--) {
            for (int x = a.size() - 1; x >= 0; x--) {
                if (a[y][x] == 'X')
                    continue;
                
                static vector<int> dy = { 1, 1, 0 };
                static vector<int> dx = { 0, 1, 1 };
                
                for (int d = 0; d < dy.size(); d++) {
                    int ty = y + dy[d];
                    int tx = x + dx[d];
                    
                    if (ty < a.size() && tx < a.size() && ways[ty][tx]) {
                        int tSum = a[y][x] - '0' + sum[ty][tx];
                        
                        if (sum[y][x] < tSum) {
                            sum[y][x] = tSum;
                            ways[y][x] = ways[ty][tx];
                        } else if (sum[y][x] == tSum) {
                            ways[y][x] = (ways[y][x] + ways[ty][tx]) % MOD;
                        }
                    }
                }
            }
        }
        
        return { (int)sum[0][0], (int)ways[0][0] };
    }
};