class Solution {
public:
    vector<vector<int>> colorGrid(int h, int w, vector<vector<int>> &starts) {
        vector<vector<int>> a(h, vector<int>(w));
        queue<tuple<int, int, int>> q;

        sort(starts.begin(), starts.end(), [](auto &a, auto &b) {
            return a.back() > b.back();
        });
        for (vector<int> &start : starts) {
            a[start[0]][start[1]] = start[2];
            q.push({ start[0], start[1], start[2] });
        }

        while (!q.empty()) {
            auto [y, x, color] = q.front();
            q.pop();

            static vector<int> dy = { -1, 0, 1, 0 };
            static vector<int> dx = { 0, 1, 0, -1 };

            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];

                if (0 <= ty && ty < h && 0 <= tx && tx < w && !a[ty][tx]) {
                    a[ty][tx] = color;
                    q.push({ ty, tx, color });
                }
            }
        }

        return a;
    }
};