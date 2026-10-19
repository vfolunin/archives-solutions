class Solution {
public:
    int minDeletions(vector<int> &a) {
        vector<int> minOps(a.size(), 1e9);
        for (int i = 0; i < a.size(); i++) {
            minOps[i] = i;
            for (int j = 0; j < i; j++)
                if (a[i] ^ a[j])
                    minOps[i] = min(minOps[i], minOps[j] + (i - j - 1));
        }
        return minOps.back();
    }
};