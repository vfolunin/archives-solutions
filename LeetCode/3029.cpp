class Solution {
public:
    int minimumTimeToInitialState(string &s, int k) {
        int res = 1;
        while (res * k < s.size() && s.substr(0, s.size() - res * k) != s.substr(res * k))
            res++;
        return res;
    }
};