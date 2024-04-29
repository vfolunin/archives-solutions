class Solution {
public:
    int numberOfStableArrays(int limit0, int limit1, int limit) {
        const long long MOD = 1e9 + 7;

        vector ways(limit0 + 1, vector(limit1 + 1, vector<long long>(2)));
        vector p(limit0 + 1, vector(limit1 + 1, vector<long long>(2)));
        for (int count0 = 0; count0 <= limit0 && count0 <= limit; count0++)
            ways[count0][0][0] = p[count0][0][0] = 1;
        for (int count1 = 0; count1 <= limit1 && count1 <= limit; count1++)
            ways[0][count1][1] = p[0][count1][1] = 1;

        for (int count0 = 1; count0 <= limit0; count0++) {
            for (int count1 = 1; count1 <= limit1; count1++) {
                ways[count0][count1][0] = (p[count0 - 1][count1][1] - (count0 > limit ? p[count0 - limit - 1][count1][1] : 0) + MOD) % MOD;
                ways[count0][count1][1] = (p[count0][count1 - 1][0] - (count1 > limit ? p[count0][count1 - limit - 1][0] : 0) + MOD) % MOD;
                
                p[count0][count1][0] = (p[count0][count1 - 1][0] + ways[count0][count1][0]) % MOD;
                p[count0][count1][1] = (p[count0 - 1][count1][1] + ways[count0][count1][1]) % MOD;
            }
        }

        return (ways[limit0][limit1][0] + ways[limit0][limit1][1]) % MOD;
    }
};