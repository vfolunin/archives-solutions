class Solution {
public:
    long long countAlternatingSubarrays(vector<int> &a) {
        long long row = 1, res = 0;
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1] != a[i]) {
                row++;
            } else {
                res += row * (row + 1) / 2;
                row = 1;
            }
        }
        res += row * (row + 1) / 2;
        return res;
    }
};