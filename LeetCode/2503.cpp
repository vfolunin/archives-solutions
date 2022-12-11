class Solution {
public:
    vector<int> maxPoints(vector<vector<int>> &a, vector<int> &queries) {
        vector<int> order(queries.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        int h = a.size(), w = a[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        int visitedCount = 0;
        set<pair<int, pair<int, int>>> q = { { a[0][0], { 0, 0 } } };
        vector<int> res(queries.size());

        for (int qi : order) {
            while (!q.empty() && queries[qi] > q.begin()->first) {
                auto [y, x] = q.begin()->second;
                q.erase(q.begin());

                visited[y][x] = 1;
                visitedCount++;

                static vector<int> dy = { -1, 0, 1, 0 };
                static vector<int> dx = { 0, 1, 0, -1 };

                for (int d = 0; d < dy.size(); d++) {
                    int ty = y + dy[d];
                    int tx = x + dx[d];

                    if (0 <= ty && ty < h && 0 <= tx && tx < w && !visited[ty][tx])
                        q.insert({ a[ty][tx], {ty, tx} });
                }
            }
            res[qi] = visitedCount;
        }

        return res;
    }
};