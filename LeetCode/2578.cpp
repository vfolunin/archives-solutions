class Solution {
public:
    int splitNum(int value) {
        string s = to_string(value);
        sort(s.begin(), s.end());

        long long res = 1e18;        
        do {
            for (int i = 1; i < s.size(); i++) {
                long long a = stoll(s.substr(0, i));
                long long b = stoll(s.substr(i));
                res = min(res, a + b);
            }
        } while (next_permutation(s.begin(), s.end()));
        
        return res;
    }
};