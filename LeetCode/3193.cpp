class Solution {
public:
    int numberOfPermutations(int targetSize, vector<vector<int>> &requirements) {
        unordered_map<int, int> reqMap;
        for (vector<int> &req : requirements)
            reqMap[req[0] + 1] = req[1];

        const int MOD = 1e9 + 7;
        vector<vector<int>> ways(targetSize + 1, vector<int>(401));
        ways[0][0] = 1;
        
        for (int size = 1; size <= targetSize; size++) {
            int sum = 0;
            for (int inv = 0; inv <= size * (size - 1) / 2 && inv < ways[size].size(); inv++) {
                int sum = 0;
                for (int addedInv = 0; addedInv <= inv && addedInv < size; addedInv++)
                    sum = (sum + ways[size - 1][inv - addedInv]) % MOD;
                ways[size][inv] = !reqMap.count(size) || reqMap[size] == inv ? sum : 0;
            }
        }

        int res = 0;
        for (int inversions = 0; inversions < ways[targetSize].size(); inversions++)
            res = (res + ways[targetSize][inversions]) % MOD;
        return res;
    }
};