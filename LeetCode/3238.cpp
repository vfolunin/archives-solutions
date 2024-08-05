class Solution {
public:
    int winningPlayerCount(int size, vector<vector<int>> &a) {
        vector<unordered_map<int, int>> count(size);
        vector<int> maxCount(size);

        for (int i = 0; i < a.size(); i++)
            maxCount[a[i][0]] = max(maxCount[a[i][0]], ++count[a[i][0]][a[i][1]]);

        int res = 0;
        for (int i = 0; i < maxCount.size(); i++)
            res += maxCount[i] > i;
        return res;
    }
};