class Solution {
public:
    long long numGoodSubarrays(vector<int> &a, int divisor) {
        vector<pair<long long, long long>> parts;
        for (int value : a) {
            if (parts.empty() || parts.back().first < value)
                parts.push_back({ value, 1 });
            else
                parts.back().second++;
        }

        unordered_map<long long, long long> prefixModCount;
        long long prefixMod = 0;
        prefixModCount[prefixMod]++;

        long long res = 0;
        for (auto &[value, count] : parts) {
            for (int i = 1; i <= count; i++)
                res += prefixModCount[(prefixMod + value * i) % divisor];
            
            for (int i = 1; i <= count; i++)
                prefixModCount[(prefixMod + value * i) % divisor]++;
            
            prefixMod = (prefixMod + value * count) % divisor;
        }

        return res;
    }
};