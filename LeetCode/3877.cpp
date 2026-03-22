class Solution {
public:
    int minRemovals(vector<int> &a, int target) {
        int lSize = a.size() / 2, rSize = a.size() - lSize;
        
        unordered_map<int, int> lXorOnes;
        for (int mask = 0; mask < (1 << lSize); mask++) {
            int xorValue = 0;
            int ones = 0;

            for (int bit = 0; bit < lSize; bit++) {
                if (mask & (1 << bit)) {
                    xorValue ^= a[bit];
                    ones++;
                }
            }

            lXorOnes[xorValue] = max(lXorOnes[xorValue], ones);
        }

        int res = -1;
        for (int mask = 0; mask < (1 << rSize); mask++) {
            int xorValue = 0;
            int ones = 0;

            for (int bit = 0; bit < rSize; bit++) {
                if (mask & (1 << bit)) {
                    xorValue ^= a[lSize + bit];
                    ones++;
                }
            }

            int lXorValue = target ^ xorValue;
            if (auto it = lXorOnes.find(lXorValue); it != lXorOnes.end())
                res = max(res, it->second + ones);
        }

        return res == -1 ? res : a.size() - res;
    }
};