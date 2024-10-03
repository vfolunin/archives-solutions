class Solution {
    int rec(int step, vector<int> &used) {
        if (step == used.size())
            return 1;
        
        int res = 0;
        for (int i = 0; i < used.size(); i++) {
            if (!used[i] && gcd(i + 1, step + 1) == 1) {
                used[i] = 1;
                res += rec(step + 1, used);
                used[i] = 0;
            }
        }
        return res;
    }

public:
    int selfDivisiblePermutationCount(int size) {
        vector<int> used(size);
        return rec(0, used);
    }
};