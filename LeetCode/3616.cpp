class Solution {
public:
    int totalReplacements(vector<int> &a) {
        int best = a[0], res = 0;
        for (int value : a) {
            if (best > value) {
                best = value;
                res++;
            }
        }
        return res;
    }
};