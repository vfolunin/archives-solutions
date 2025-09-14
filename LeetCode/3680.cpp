class Solution {
public:
    vector<vector<int>> generateSchedule(int teamCount) {
        if (teamCount <= 4)
            return {};

        vector<vector<int>> played(teamCount, vector<int>(teamCount));
        vector<int> matches(teamCount);
        vector<vector<int>> res;

        for (int i = 0; i < teamCount * (teamCount - 1); i++) {
            int curA = -1, curB = -1;

            for (int a = 0; a < teamCount; a++) {
                if (!res.empty() && (a == res.back()[0] || a == res.back()[1]))
                    continue;

                for (int b = 0; b < teamCount; b++) {
                    if (a == b || played[a][b] || !res.empty() && (b == res.back()[0] || b == res.back()[1]))
                        continue;
                    
                    if (curA == -1 || matches[curA] + matches[curB] > matches[a] + matches[b]) {
                        curA = a;
                        curB = b;
                    }
                }
            }

            played[curA][curB] = 1;
            matches[curA]++;
            matches[curB]++;
            res.push_back({ curA, curB });
        }

        return res;
    }
};