class Solution {
    int rec(vector<int> &a, int i, vector<int> &sums) {
        if (i == a.size())
            return *max_element(sums.begin(), sums.end());
        
        int res = 1e9;
        for (int &sum : sums) {
            sum += a[i];
            res = min(res, rec(a, i + 1, sums));
            sum -= a[i];
        }
        return res;
    }
    
public:
    int distributeCookies(vector<int> &a, int k) {
        vector<int> sums(k);
        return rec(a, 0, sums);
    }
};