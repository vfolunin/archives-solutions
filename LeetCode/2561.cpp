class Solution {
public:
    long long minCost(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> aCount;
        for (int value : a)
            aCount[value]++;
        
        unordered_map<int, int> bCount;
        for (int value : b)
            bCount[value]++;
        
        set<int> values(a.begin(), a.end());
        values.insert(b.begin(), b.end());

        vector<int> aSwap, bSwap;
        for (int value : values) {
            int ak = aCount[value], bk = bCount[value];
            if ((ak + bk) % 2)
                return -1;

            if (ak > bk) {
                for ( ; ak > bk; ak--, bk++)
                    aSwap.push_back(value);
            } else if (ak < bk) {
                for ( ; ak < bk; ak++, bk--)
                    bSwap.push_back(value);
            }
        }
        
        if (aSwap.size() != bSwap.size())
            return -1;
        
        sort(aSwap.begin(), aSwap.end());
        sort(bSwap.rbegin(), bSwap.rend());
        int minValue = *values.begin();
        
        long long res = 0;
        for (int i = 0; i < aSwap.size(); i++)
            res += min({ aSwap[i], bSwap[i], 2 * minValue });
        return res;
    }
};