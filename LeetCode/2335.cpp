class Solution {
public:
    int fillCups(vector<int> &a) {
        int res = 0;
        while (1) {
            sort(a.begin(), a.end());
            if (a[1] && a[2]) {
                res++;
                a[1]--;
                a[2]--;
            } else {
                break;
            }
        }
        res += a[2];
        return res;
    }
};