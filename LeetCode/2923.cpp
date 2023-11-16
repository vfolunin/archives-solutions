class Solution {
public:
    int findChampion(vector<vector<int>> &a) {
        int res = 0;
        for (int i = 1; i < a.size(); i++)
            if (a[i][res])
                res = i;
        return res;
    }
};