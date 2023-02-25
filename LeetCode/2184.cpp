class Solution {
    void rec(vector<int> &a, int width, vector<int> &row, vector<vector<int>> &rows) {
        if (!width) {
            rows.push_back(row);
            return;
        }

        for (int value : a) {
            if (width >= value) {
                row.push_back(value);
                rec(a, width - value, row, rows);
                row.pop_back();
            }
        }
    }

    bool compatible(vector<int> &a, vector<int> &b) {
        unordered_set<int> aSums;
        int aSum = 0;
        for (int i = 0; i + 1 < a.size(); i++) {
            aSum += a[i];
            aSums.insert(aSum);
        }

        int bSum = 0;
        for (int i = 0; i + 1 < b.size(); i++) {
            bSum += b[i];
            if (aSums.count(bSum))
                return 0;
        }

        return 1;
    }

public:
    int buildWall(int height, int width, vector<int> &a) {
        vector<int> row;
        vector<vector<int>> rows;
        rec(a, width, row, rows);

        vector<vector<int>> prev(rows.size());
        for (int i = 0; i < rows.size(); i++)
            for (int j = 0; j < rows.size(); j++)
                if (compatible(rows[i], rows[j]))
                    prev[j].push_back(i);
        
        const long long MOD = 1e9 + 7;
        
        vector<vector<long long>> ways(height, vector<long long>(rows.size()));
        fill(ways[0].begin(), ways[0].end(), 1);

        for (int y = 1; y < height; y++)
            for (int i = 0; i < rows.size(); i++)
                for (int j : prev[i])
                    ways[y][i] = (ways[y][i] + ways[y - 1][j]) % MOD;
        
        long long res = 0;
        for (int i = 0; i < rows.size(); i++)
            res = (res + ways[height - 1][i]) % MOD;
        return res;
    }
};