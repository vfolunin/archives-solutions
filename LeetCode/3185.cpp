class Solution {
public:
    long long countCompleteDayPairs(vector<int> &a) {
        vector<long long> count(24);
        for (int value : a)
            count[value % 24]++;
        
        long long res = count[0] * (count[0] - 1) / 2;
        for (int l = 1, r = 23; l < r; l++, r--)
            res += count[l] * count[r];
        res += count[12] * (count[12] - 1) / 2;
        return res;
    }
};