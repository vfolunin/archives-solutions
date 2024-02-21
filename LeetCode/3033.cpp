class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &a) {
        vector<int> colMax(a[0].size());
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                colMax[x] = max(colMax[x], a[y][x]);
        
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                if (a[y][x] == -1)
                    a[y][x] = colMax[x];

        return a;
    }
};