class NumArray {
    vector<int> p;
    
public:
    NumArray(vector<int> &a) {
        p.resize(a.size());
        partial_sum(a.begin(), a.end(), p.begin());
    }
    
    int sumRange(int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
};