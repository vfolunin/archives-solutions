class Solution {
    void rec(int index, int n, vector<int> &used, int &res) {
        if (index == n) {
            res++;
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (!used[i] && ((i + 1) % (n - index) == 0 || (n - index) % (i + 1) == 0)) {
                used[i] = 1;
                rec(index + 1, n, used, res);
                used[i] = 0;
            }
        }
    }
    
public:
    int countArrangement(int n) {
        vector<int> used(n);
        int res = 0;
        rec(0, n, used, res);
        return res;
    }
};