class Solution {
public:
    long long maxScore(vector<int> &a) {
        vector<int> to(a.size(), a.size());
        for (int i = (int)a.size() - 2; i >= 0; i--)
            to[i] = (to[i + 1] == a.size() || a[i + 1] > a[to[i + 1]] ? i + 1 : to[i + 1]);
        
        long long res = 0;
        for (int i = 0; i + 1 < a.size(); i = to[i])
            res += (long long)(to[i] - i) * a[to[i]];
        return res;
    }
};