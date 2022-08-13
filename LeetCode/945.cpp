class Solution {
public:
    int minIncrementForUnique(vector<int> &a) {
        sort(a.begin(), a.end());
        
        int res = 0;
        
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1] >= a[i]) {
                res += a[i - 1] + 1 - a[i];
                a[i] = a[i - 1] + 1;
            }
        }
        
        return res;
    }
};