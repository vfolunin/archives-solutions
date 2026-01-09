class Solution {
public:
    string minCostGoodCaption(string &s) {
        if (s.size() < 3)
            return "";

        vector<array<array<pair<int, int>, 3>, 26>> cost(s.size() + 1);
        for (int i = 0; i <= s.size(); i++)
            for (int c = 0; c < 26; c++)
                cost[i][c].fill({ 1e9, -1 });

        for (int c = 0; c < 26; c++)
            cost.back()[c][2] = { 0, -1 };

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int c = 0; c < 26; c++) {
                for (int count = 0; count < 3; count++)
                    cost[i][c][count] = { abs(s[i] - 'a' - c) + cost[i + 1][c][min(count + 1, 2)].first, c };
                
                if (i + 3 < s.size())
                    for (int nextC = 0; nextC < 26; nextC++)
                        if (c != nextC)
                            cost[i][c][2] = min(cost[i][c][2], { abs(s[i] - 'a' - c) + cost[i + 1][nextC][0].first, nextC });
            }
        }

        pair<int, int> resCost = { 1e9, -1 };
        for (int c = 0; c < 26; c++)
            resCost = min(resCost, cost[0][c][0]);

        string res(1, resCost.second + 'a');
        for (int i = 0, count = 0; i + 1 < s.size(); i++) {
            res += cost[i][res.back() - 'a'][count].second + 'a';
            count = res[i] == res[i + 1] ? min(count + 1, 2) : 0;
        }
        return res;
    }
};