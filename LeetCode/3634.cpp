class Solution {
public:
    int minRemoval(vector<int> &a, long long factor) {
        sort(a.begin(), a.end());

        int res = 1;
        for (int l = 0, r = 0; r < a.size(); r++) {
            while (a[l] * factor < a[r])
                l++;
            res = max(res, r - l + 1);
        }
        
        return a.size() - res;
    }
};