class Solution {
public:
    long long countMagicalPairs(string &s) {
        vector<int> pos(26, -1);
        vector<vector<int>> countL(s.size(), vector<int>(27));
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'] = i;

            vector<int> sortedPos = pos;
            sortedPos.erase(remove(sortedPos.begin(), sortedPos.end(), -1), sortedPos.end());
            sort(sortedPos.rbegin(), sortedPos.rend());
            sortedPos.push_back(-1);

            for (int uniqueCount = 1; uniqueCount < sortedPos.size(); uniqueCount++)
                countL[i][uniqueCount] = sortedPos[uniqueCount - 1] - sortedPos[uniqueCount];
        }

        pos.assign(26, s.size());
        vector<vector<int>> countR(s.size(), vector<int>(27));
        for (int i = s.size() - 1; i >= 0; i--) {
            pos[s[i] - 'a'] = i;

            vector<int> sortedPos = pos;
            sortedPos.erase(remove(sortedPos.begin(), sortedPos.end(), s.size()), sortedPos.end());
            sort(sortedPos.begin(), sortedPos.end());
            sortedPos.push_back(s.size());

            for (int uniqueCount = 1; uniqueCount < sortedPos.size(); uniqueCount++)
                countR[i][uniqueCount] = sortedPos[uniqueCount] - sortedPos[uniqueCount - 1];
        }

        long long res = 0;
        for (int i = 0; i + 1 < s.size(); i++)
            for (int uniqueCount = 1; uniqueCount <= 26; uniqueCount++)
                res += 1LL * countL[i][uniqueCount] * countR[i + 1][uniqueCount];
        return res;
    }
};