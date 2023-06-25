class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int> &a) {
        vector<int> onePos;
        for (int i = 0; i < a.size(); i++)
            if (a[i] == 1)
                onePos.push_back(i);
        
        if (onePos.empty())
            return 0;
        
        const long long MOD = 1e9 + 7;
        long long res = 1;
        
        for (int i = 1; i < onePos.size(); i++)
            res = res * (onePos[i] - onePos[i - 1]) % MOD;
        
        return res;
    }
};