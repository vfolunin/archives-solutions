class Solution {
public:
    vector<int> decode(vector<int> &a) {
        int xorSum = 0;
        for (int i = 1; i <= a.size() + 1; i++)
            xorSum ^= i;
        
        vector<int> res(a.size() + 1);
        
        res[0] = xorSum;
        for (int i = 1; i < a.size(); i += 2)
            res[0] ^= a[i];
        
        for (int i = 1; i < res.size(); i++)
            res[i] = res[i - 1] ^ a[i - 1];
        
        return res;
    }
};