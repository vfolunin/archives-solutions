class Solution {
public:
    vector<int> shuffle(vector<int> &a, int n) {
        vector<int> res(a.size());
        for (int i = 0; i < n; i++) {
            res[i * 2] = a[i];
            res[i * 2 + 1] = a[i + n];
        }
        return res;
    }
};