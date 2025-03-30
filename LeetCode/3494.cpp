class Solution {
public:
    long long minTime(vector<int> &skill, vector<int> &mana) {
        vector<vector<long long>> res(mana.size(), vector<long long>(skill.size()));
        for (int y = 0; y < mana.size(); y++) {
            for (int x = 0; x < skill.size(); x++) {
                if (y)
                    res[y][x] = max(res[y][x], res[y - 1][x]);
                if (x)
                    res[y][x] = max(res[y][x], res[y][x - 1]);
                res[y][x] += mana[y] * skill[x];
            }
            for (int x = (int)skill.size() - 2; x >= 0; x--)
                res[y][x] = res[y][x + 1] - mana[y] * skill[x + 1];
        }
        return res.back().back();
    }
};