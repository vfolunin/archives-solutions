class Solution {
public:
    void merge(vector<int> &a, int an, vector<int> &b, int bn) {
        vector<int> &r = a;
        
        int ai = an - 1;
        int bi = bn - 1;
        
        for (int ri = r.size() - 1; ri >= 0; ri--) {
            if (bi < 0 || ai >= 0 && a[ai] > b[bi]) {
                r[ri] = a[ai];
                ai--;
            } else {
                r[ri] = b[bi];
                bi--;
            }
        }
    }
};