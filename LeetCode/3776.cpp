class Solution {
public:
    long long minMoves(vector<int> &a) {
        if (accumulate(a.begin(), a.end(), 0LL) < 0)
            return -1;
        
        int i = 0;
        while (i < a.size() && a[i] >= 0)
            i++;
        if (i == a.size())
            return 0;
        
        long long res = 0;
        for (int dist = 1; a[i] < 0; dist++) {
            int l = (i - dist + a.size()) % a.size();
            int delta = min(a[l], -a[i]);
            a[l] -= delta;
            a[i] += delta;
            res += 1LL * dist * delta;

            if (a[i] < 0) {
                int r = (i + dist) % a.size();
                int delta = min(a[r], -a[i]);
                a[r] -= delta;
                a[i] += delta;
                res += 1LL * dist * delta;
            }
        }
        return res;
    }
};