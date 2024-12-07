class Solution {
    int getTime(vector<int> &a, int factorDelta) {
        int factor = 1, time = 0;
        for (int value : a) {
            time += (value + factor - 1) / factor;
            factor += factorDelta;
        }
        return time;
    }

public:
    int findMinimumTime(vector<int> &a, int factorDelta) {
        sort(a.begin(), a.end());
        int res = 1e9;
        do {
            res = min(res, getTime(a, factorDelta));
        } while (next_permutation(a.begin(), a.end()));
        return res;
    }
};