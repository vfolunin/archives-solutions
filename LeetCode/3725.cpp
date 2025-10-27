class Solution {
public:
    int countCoprime(vector<vector<int>> &a) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> ways(a.size(), vector<int>(151));

        for (int x = 0; x < a[0].size(); x++)
            ways[0][a[0][x]]++;
        
        for (int y = 1; y < a.size(); y++)
            for (int g = 0; g < ways[0].size(); g++)
                for (int x = 0; x < a[0].size(); x++)
                    ways[y][gcd(g, a[y][x])] = (ways[y][gcd(g, a[y][x])] + ways[y - 1][g]) % MOD;
        
        return ways.back()[1];
    }
};