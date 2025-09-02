class Solution {
public:
    int countOfArrays(int targetSize, int valueLimit, int targetCount) {
        int evenValueCount = valueLimit / 2;
        int oddValueCount = (valueLimit + 1) / 2;

        const long long MOD = 1e9 + 7;
        vector ways(targetSize + 1, vector(targetCount + 1, vector<long long>(2)));
        ways[1][0] = { evenValueCount, oddValueCount };

        for (int size = 2; size <= targetSize; size++) {
            ways[size][0][0] = ways[size - 1][0][1] * evenValueCount % MOD;
            ways[size][0][1] = (ways[size - 1][0][0] + ways[size - 1][0][1]) * oddValueCount % MOD;

            for (int count = 1; count <= targetCount; count++) {
                ways[size][count][0] = (ways[size - 1][count][1] + ways[size - 1][count - 1][0]) * evenValueCount % MOD;
                ways[size][count][1] = (ways[size - 1][count][0] + ways[size - 1][count][1]) * oddValueCount % MOD;
            }
        }

        return (ways[targetSize][targetCount][0] + ways[targetSize][targetCount][1]) % MOD;
    }
};