class Solution {
public:
    int maxEqualAdjacentPairs(vector<int> &a) {
        int pairedCount = 0;
        for (int i = 0; i + 1 < a.size(); i++)
            pairedCount += a[i] == a[i + 1];
        a.erase(unique(a.begin(), a.end()), a.end());

        int changedCount = 0;
        unordered_map<int, unordered_map<int, int>> count;
        for (int i = 0; i + 1 < a.size(); i++) {
            changedCount = max(changedCount, ++count[a[i]][a[i + 1]]);
            changedCount = max(changedCount, ++count[a[i + 1]][a[i]]);
        }

        return pairedCount + changedCount;
    }
};