class Solution {
public:
    int countTrapezoids(vector<vector<int>> &points) {
        unordered_map<int, long long> yCount;
        for (vector<int> &point : points)
            yCount[point[1]]++;
        
        const long long MOD = 1e9 + 7;
        long long sum = 0;
        for (auto &[y, count] : yCount) {
            count = (count * (count - 1) / 2) % MOD;
            sum = (sum + count) % MOD;
        }

        long long res = 0;
        for (auto &[y, count] : yCount) 
            res += count * ((sum - count + MOD) % MOD) % MOD;
        return res / 2 % MOD;
    }
};