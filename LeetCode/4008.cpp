class Solution {
    bool can(vector<int> &monsters, vector<long long> deltas, long long strength) {
        long long bonus = 0;
        for (int i = 0; i < monsters.size(); i++) {
            bonus += deltas[i];
            if (strength + bonus < monsters[i])
                return 0;
            strength = max(strength - monsters[i], 0LL);
        }
        return 1;
    }

public:
    long long minInitialStrength(vector<int> &monsters, vector<vector<int>> &boosts) {
        vector<long long> deltas(monsters.size() + 1);
        for (vector<int> &boost : boosts) {
            deltas[boost[0]] += boost[2];
            deltas[boost[1] + 1] -= boost[2];
        }

        long long l = -1, r = 1;
        while (!can(monsters, deltas, r))
            r *= 2;
        
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(monsters, deltas, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};