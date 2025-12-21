class Solution {
public:
    long long maximumScore(vector<int> &a, string &s) {
        multiset<int> values;
        long long res = 0;
        for (int i = 0; i < a.size(); i++) {
            values.insert(a[i]);
            if (s[i] == '1') {
                res += *prev(values.end());
                values.erase(prev(values.end()));
            }
        }
        return res;
    }
};