class Solution {
    bool rec(vector<int> &a, int divisor, int mask, int mod, 
             vector<int> &sizes, int totalSize, vector<int> &pows, vector<vector<int>> &memo) {
        int &res = memo[mask][mod];
        if (res != -1)
            return res;
        
        if (!mask)
            return res = !mod;
        
        for (int bit = 0; bit < a.size(); bit++) {
            if (!(mask & (1 << bit)))
                continue;
            
            int nextMask = mask ^ (1 << bit);
            int curMod = a[bit] % divisor * pows[totalSize - sizes[bit]] % divisor;
            int nextMod = (mod - curMod + divisor) % divisor;
            int nextTotalSize = totalSize - sizes[bit];

            if (rec(a, divisor, nextMask, nextMod, sizes, nextTotalSize, pows, memo))
                return res = 1;
        }

        return res = 0;
    }

public:
    vector<int> concatenatedDivisibility(vector<int> &a, int divisor) {
        sort(a.begin(), a.end());

        vector<int> sizes(a.size());
        int totalSize = 0;
        for (int i = 0; i < a.size(); i++) {
            sizes[i] = to_string(a[i]).size();
            totalSize += sizes[i];
        }

        vector<int> pows(totalSize + 1, 1 % divisor);
        for (int i = 1; i <= totalSize; i++)
            pows[i] = pows[i - 1] * 10 % divisor;
        
        vector<vector<int>> memo(1 << a.size(), vector<int>(divisor, -1));

        int mask = (1 << a.size()) - 1, mod = 0;
        vector<int> res;
        
        while (mask) {
            bool found = 0;

            for (int bit = 0; bit < a.size(); bit++) {
                if (!(mask & (1 << bit)))
                    continue;
                
                int nextMask = mask ^ (1 << bit);
                int curMod = a[bit] % divisor * pows[totalSize - sizes[bit]] % divisor;
                int nextMod = (mod - curMod + divisor) % divisor;
                int nextTotalSize = totalSize - sizes[bit];

                if (rec(a, divisor, nextMask, nextMod, sizes, nextTotalSize, pows, memo)) {
                    res.push_back(a[bit]);
                    mask = nextMask;
                    mod = nextMod;
                    totalSize = nextTotalSize;
                    found = 1;
                    break;
                }
            }

            if (!found)
                return {};
        }
        
        return res;
    }
};