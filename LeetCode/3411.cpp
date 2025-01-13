class Solution {
public:
    int maxLength(vector<int> &a) {
        int res = 0;

        for (int l = 0; l < a.size(); l++) {
            long long gcdValue = a[l], lcmValue = a[l], prodValue = 1;
            for (int r = l; prodValue < 1e10 && r < a.size(); r++) {
                gcdValue = gcd(gcdValue, a[r]);
                lcmValue = lcm(lcmValue, a[r]);
                prodValue *= a[r];

                if (gcdValue * lcmValue == prodValue)
                    res = max(res, r - l + 1);
            }
        }

        return res;
    }
};