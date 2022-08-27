class Solution {
    int getNth(vector<int> &a, vector<int> &b, int n) {
        int l = -2e6, r = 2e6;
        
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            
            int index = lower_bound(a.begin(), a.end(), m) - a.begin();
            index += lower_bound(b.begin(), b.end(), m) - b.begin();
            
            if (index <= n)
                l = m;
            else
                r = m;
        }
        
        return l;
    }
    
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b) {
        if ((a.size() + b.size()) % 2)
            return getNth(a, b, (a.size() + b.size()) / 2);
        
        double res = getNth(a, b, (a.size() + b.size()) / 2 - 1);
        res += getNth(a, b, (a.size() + b.size()) / 2);
        return res / 2;
    }
};