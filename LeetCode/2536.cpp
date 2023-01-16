class Solution {
public:
    vector<vector<int>> rangeAddQueries(int size, vector<vector<int>> &queries) {
        vector<vector<int>> p(size, vector<int>(size));
        for (int i = 0; i < queries.size(); i++) {
            p[queries[i][0]][queries[i][1]]++;
            if (queries[i][2] + 1 < size)
                p[queries[i][2] + 1][queries[i][1]]--;
            if (queries[i][3] + 1 < size)
                p[queries[i][0]][queries[i][3] + 1]--;
            if (queries[i][2] + 1 < size && queries[i][3] + 1 < size)
                p[queries[i][2] + 1][queries[i][3] + 1]++;
        }

        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                if (y)
                    p[y][x] += p[y - 1][x];
                if (x)
                    p[y][x] += p[y][x - 1];
                if (y && x)
                    p[y][x] -= p[y - 1][x - 1];
            }
        }
        
        return p;
    }
};