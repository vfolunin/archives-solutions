class Solution {
public:
    int singleNumber(vector<int> &a) {
        vector<int> bitCount(32);
        for (int &value : a)
            for (int bit = 0; bit < bitCount.size(); bit++)
                bitCount[bit] += (bool)(value & (1ULL << bit));
        
        int res = 0;
        for (int bit = 0; bit < bitCount.size(); bit++)
            if (bitCount[bit] % 3)
                res += (1ULL << bit);
        return res;
    }
};