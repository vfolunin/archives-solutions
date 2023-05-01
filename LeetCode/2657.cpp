class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b) {
        vector<int> res(a.size());
        for (int i = 0; i < res.size(); i++) {
            for (int ai = 0; ai <= i; ai++) {
                int bi = find(b.begin(), b.end(), a[ai]) - b.begin();
                res[i] += bi <= i;
            }
        }
        return res;
    }
};