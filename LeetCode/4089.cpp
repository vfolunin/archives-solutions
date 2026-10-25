class Solution {
public:
    long long countSubarrays(vector<int> &a, int l, int r) {
        long long row = 0, res = 0;
        for (int value : a) {
            if (l <= value && value <= r)
                row++;
            else
                row = 0;
            res += row;
        }
        return res;
    }
};