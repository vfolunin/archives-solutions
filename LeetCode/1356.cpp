class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }
    
public:
    vector<int> sortByBits(vector<int> &a) {
        sort(a.begin(), a.end(), [this](int a, int b) {
            if (int a1 = ones(a), b1 = ones(b); a1 != b1)
                return a1 < b1;
            return a < b;
        });
        return a;
    }
};