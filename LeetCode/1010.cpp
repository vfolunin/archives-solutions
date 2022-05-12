class Solution {
public:
    int numPairsDivisibleBy60(vector<int> &time) {
        vector<long long> count(60);
        for (int t : time)
            count[t % 60]++;
        
        long long res = count[0] * (count[0] - 1) / 2;
        for (int l = 1, r = 59; l < r; l++, r--)
            res += count[l] * count[r];
        res += count[30] * (count[30] - 1) / 2;
        
        return res;
    }
};