class Solution {
public:
    int makeArrayPositive(vector<int> &values) {
        vector<long long> a(values.begin(), values.end());
        int res = 0;

        for (int i = 2; i < a.size(); i++) {
            for (int size = 3; size <= 5 && size <= i + 1; size++) {
                if (accumulate(a.begin() + i - size + 1, a.begin() + i + 1, 0LL) <= 0) {
                    res++;
                    a[i] = 1e12;
                }
            }
        }

        return res;
    }
};