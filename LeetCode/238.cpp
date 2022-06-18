class Solution {
public:
    vector<int> productExceptSelf(vector<int> &a) {
        vector<int> res(a.size());
        res[0] = 1;
        for (int i = 1; i < a.size(); i++)
            res[i] = res[i - 1] * a[i - 1];

        int suffixProfuct = 1;
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] *= suffixProfuct;
            suffixProfuct *= a[i];
        }
        
        return res;
    }
};