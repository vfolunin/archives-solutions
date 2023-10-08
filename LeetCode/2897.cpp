class Solution {
public:
    int maxSum(vector<int> &a, int size) {
        vector<int> count(30);
        for (int &value : a)
            for (int bit = 0; bit < count.size(); bit++)
                count[bit] += (bool)(value & (1 << bit));
        
        vector<long long> values(size);
        for (int bit = 0; bit < count.size(); bit++)
            for (int i = 0; i < size && i < count[bit]; i++)
                values[i] |= 1 << bit;
        
        const long long MOD = 1e9 + 7;
        long long res = 0;
        for (long long value : values)
            res = (res + value * value) % MOD;
        return res;
    }
};