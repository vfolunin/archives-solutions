class Solution {
public:
    int minOperations(vector<int> &a) {
        int res = 0;
        for (int i = 0; i + 2 < a.size(); i++) {
            if (!a[i]) {
                res++;
                a[i + 1] ^= 1;
                a[i + 2] ^= 1;
            }
        }
        return a[a.size() - 2] && a[a.size() - 1] ? res : -1;
    }
};