class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int> &a) {
        vector<bool> res(a.size());
        int mod = 0;
        for (int i = 0; i < a.size(); i++) {
            mod = (mod * 2 + a[i]) % 5;
            res[i] = !mod;
        }
        return res;
    }
};