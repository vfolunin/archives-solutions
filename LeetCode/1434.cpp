class Solution {
    long long rec(int hatCount, int mask, vector<vector<int>> &personsOf, vector<vector<long long>> &memo) {
        long long &res = memo[hatCount][mask];
        if (res != -1)
            return res;

        const long long MOD = 1e9 + 7;

        if (!hatCount)
            return res = !mask;

        res = rec(hatCount - 1, mask, personsOf, memo);
        for (int pi : personsOf[hatCount - 1])
            if (mask & (1 << pi))
                res = (res + rec(hatCount - 1, mask ^ (1 << pi), personsOf, memo)) % MOD;
        return res;
    }

public:
    int numberWays(vector<vector<int>> &hatsOf) {
        vector<vector<int>> personsOf(40);
        for (int person = 0; person < hatsOf.size(); person++)
            for (int hat : hatsOf[person])
                personsOf[hat - 1].push_back(person);

        vector<vector<long long>> memo(41, vector<long long>(1 << hatsOf.size(), -1));
        return rec(40, (1 << hatsOf.size()) - 1, personsOf, memo);
    }
};