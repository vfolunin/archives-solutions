class Solution {
public:
    int minOperations(vector<int> &a) {
        int ones = count(a.begin(), a.end(), 1);
        if (ones)
            return a.size() - ones;

        int len = a.size() + 1;
        for (int l = 0; l < a.size(); l++) {
            int d = a[l];
            for (int r = l; r < a.size(); r++) {
                d = gcd(d, a[r]);
                if (d == 1)
                    len = min(len, r - l + 1);
            }
        }
        return len <= a.size() ? a.size() + len - 2 : -1;
    }
};