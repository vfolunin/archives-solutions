class Solution {
public:
    int knightDialer(int n) {
        const long long MOD = 1e9 + 7;
        
        vector<vector<long long>> ways(n + 1, vector<long long>(10));
        fill(ways[1].begin(), ways[1].end(), 1);
        
        vector<vector<int>> to = {
            { 4, 6 }, { 6, 8 }, { 7, 9 }, { 4, 8 }, { 0, 3, 9 },
            {}, { 0, 1, 7 }, { 2, 6 }, { 1, 3 }, { 2, 4 }
        };
        
        for (int i = 1; i < n; i++)
            for (int digit = 0; digit < 10; digit++)
                for (int toDigit : to[digit])
                    ways[i + 1][toDigit] = (ways[i + 1][toDigit] + ways[i][digit]) % MOD;
        
        long long res = 0;
        for (long long value : ways.back())
            res = (res + value) % MOD;
        return res;
    }
};