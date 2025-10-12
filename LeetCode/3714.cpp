class Solution {
    int solve1(string &s) {
        int res = 1, cur = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i])
                cur++;
            else
                cur = 1;
            res = max(res, cur);
        }
        return res;
    }

    int solve2(string &s, char a, char b) {
        int countA = 0, countB = 0;
        map<int, int> minPos = { { 0, -1 } };
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == a || s[i] == b) {
                countA += s[i] == a;
                countB += s[i] == b;
                int key = countA - countB;
                if (auto it = minPos.find(key); it != minPos.end())
                    res = max(res, i - it->second);
                else
                    minPos[key] = i;
            } else {
                countA = countB = 0;
                minPos = { { 0, i } };
            }
        }

        return res;
    }

    int solve3(string &s) {
        vector<int> count(3);
        map<pair<int, int>, int> minPos = { { { 0, 0 }, -1 } };
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            pair<int, int> key(count[0] - count[1], count[0] - count[2]);
            if (auto it = minPos.find(key); it != minPos.end())
                res = max(res, i - it->second);
            else
                minPos[key] = i;
        }

        return res;
    }

public:
    int longestBalanced(string &s) {
        return max({ solve1(s), solve2(s, 'a', 'b'), solve2(s, 'a', 'c'), solve2(s, 'b', 'c'), solve3(s) });
    }
};