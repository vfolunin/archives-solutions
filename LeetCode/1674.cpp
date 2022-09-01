class Solution {
public:
    int minMoves(vector<int> &a, int limit) {
        map<int, int> deltas;
        
        for (int l = 0, r = a.size() - 1; l < r; l++, r--) {
            deltas[2] += 2;
            deltas[min(a[l], a[r]) + 1]--;
            deltas[a[l] + a[r]]--;
            deltas[a[l] + a[r] + 1]++;
            deltas[max(a[l], a[r]) + limit + 1]++;
        }
        
        int res = a.size(), cur = 0;
        
        for (auto [x, delta] : deltas) {
            cur += delta;
            res = min(res, cur);
        }
        
        return res;
    }
};