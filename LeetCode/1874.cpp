class Solution {
public:
    int minProductSum(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += a[i] * b[i];
        return res;
    }
};