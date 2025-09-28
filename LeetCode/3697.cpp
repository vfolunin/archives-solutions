class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> res;
        for (long long d = 10; n; d *= 10) {
            if (n % d) {
                res.push_back(n % d);
                n -= n % d;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};