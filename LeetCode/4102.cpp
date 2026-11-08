class Solution {
public:
    long long countValidSubstrings(string &s) {
        long long res = 0;
        int from = -1;
        for (int i = 0; i < s.size(); i++) {
            if (i >= 2 && s.substr(i - 2, 3) == "abc")
                from = i - 2;
            res += i - from;
        }
        return res;
    }
};