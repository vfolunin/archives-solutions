class Solution {
public:
    vector<int> orArray(vector<int> &a) {
        vector<int> res(a.size() - 1);
        for (int i = 0; i < res.size(); i++)
            res[i] = a[i] | a[i + 1];
        return res;
    }
};