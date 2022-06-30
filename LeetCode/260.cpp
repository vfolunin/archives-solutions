class Solution {
public:
    vector<int> singleNumber(vector<int> &a) {
        int xorSum = 0;
        for (int value : a)
            xorSum ^= value;
        
        int mask = 1;
        while (!(xorSum & mask))
            mask <<= 1;
        
        vector<int> res(2);
        for (int value : a)
            res[(bool)(value & mask)] ^= value;
        return res;
    }
};