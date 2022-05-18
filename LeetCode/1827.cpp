class Solution {
public:
    int minOperations(vector<int> &a) {
        int res = 0;
        
        for (int i = 1; i < a.size(); i++) {
            res += max(0, a[i - 1] + 1 - a[i]);
            a[i] = max(a[i], a[i - 1] + 1);
        }
        
        return res;
    }
};