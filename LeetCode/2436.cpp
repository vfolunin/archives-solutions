class Solution {
public:
    int minimumSplits(vector<int> &a) {
        int curGcd = a[0], res = 1;
        for (int i = 1; i < a.size(); i++) {
            int nextGcd = gcd(curGcd, a[i]);
            if (nextGcd != 1) {
                curGcd = nextGcd;
            } else {
                res++;
                curGcd = a[i];
            }
        }
        return res;
    }
};