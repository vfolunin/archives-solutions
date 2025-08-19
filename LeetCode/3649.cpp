class Solution {
public:
    long long perfectPairs(vector<int> &a) {
        sort(a.begin(), a.end(), [](int lhs, int rhs) {
            return abs(lhs) < abs(rhs);
        });

        long long res = 0;
        for (int l = 0, r = 0; l < a.size(); l++) {
            while (r < a.size() && abs(a[l]) * 2 >= abs(a[r]))
                r++;
            res += r - l - 1;
        }
        return res;
    }
};