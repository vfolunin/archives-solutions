class Solution {
public:
    int countBeautifulPairs(vector<int> &a) {
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                int l = to_string(a[i])[0] - '0';
                int r = a[j] % 10;
                res += gcd(l, r) == 1;
            }
        }
        return res;
    }
};