class Solution {
public:
    int waysToMakeFair(vector<int> &a) {
        vector<int> l(2), r(2);
        for (int i = 0; i < a.size(); i++)
            r[i % 2] += a[i];
        
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            r[i % 2] -= a[i];
            res += l[0] + r[1] == l[1] + r[0];
            l[i % 2] += a[i];
        }
        return res;
    }
};