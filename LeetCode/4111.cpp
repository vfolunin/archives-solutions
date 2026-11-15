class Solution {
public:
    int countConsistent(vector<int> &a) {
        int res = 0;
        for (int l = 0; l < a.size(); l++) {
            int minValue = 1e9, andSum = -1;
            for (int r = l; r < a.size(); r++) {
                minValue = min(minValue, a[r]);
                andSum &= a[r];

                res += minValue == andSum;
            }
        }
        return res;
    }
};