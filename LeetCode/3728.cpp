class Solution {
public:
    long long countStableSubarrays(vector<int> &a) {
        map<pair<long long, int>, int> prefixMap;
        long long prefixSum = 0, res = 0;

        for (int i = 0; i < a.size(); i++) {
            res += prefixMap[{ prefixSum - a[i], a[i] }];
            res -= i && !a[i - 1] && !a[i];
            prefixSum += a[i];
            prefixMap[{ prefixSum, a[i] }]++;
        }

        return res;
    }
};