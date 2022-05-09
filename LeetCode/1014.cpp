class Solution {
public:
    int maxScoreSightseeingPair(vector<int> &a) {
        int maxAdd = a[0], res = 0;
        for (int i = 1; i < a.size(); i++) {
            res = max(res, a[i] - i + maxAdd);
            maxAdd = max(maxAdd, a[i] + i);
        }
        return res;
    }
};