class Solution {
public:
    int threeSumMulti(vector<int> &a, int target) {
        vector<vector<int>> suffixCount(a.size(), vector<int>(101));
        suffixCount.back()[a.back()]++;
        for (int i = a.size() - 2; i >= 0; i--) {
            suffixCount[i] = suffixCount[i + 1];
            suffixCount[i][a[i]]++;
        }
        
        long long res = 0, MOD = 1e9 + 7;
        for (int i = 0; i + 2 < a.size(); i++) {
            for (int j = i + 1; j + 1 < a.size(); j++) {
                int suffixVal = target - a[i] - a[j];
                if (0 <= suffixVal && suffixVal < suffixCount[j + 1].size())
                    res = (res + suffixCount[j + 1][suffixVal]) % MOD;
            }
        }
        return res;
    }
};