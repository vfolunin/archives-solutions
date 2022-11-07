class Solution {
public:
    long long minimumReplacement(vector<int> &a) {
        int last = a.back();
        long long res = 0;
        
        for (int i = (int)a.size() - 2; i >= 0; i--) {
            int ops = (a[i] + last - 1) / last;
            last = a[i] / ops;
            res += ops - 1;
        }
        
        return res;
    }
};