class Solution {
public:
    vector<int> constructTransformedArray(vector<int> &a) {
        vector<int> res(a.size());
        for (int i = 0; i < a.size(); i++)
            res[i] = a[(((i + a[i]) % (int)a.size()) + (int)a.size()) % a.size()];
        return res;
    }
};