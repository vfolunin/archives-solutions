struct DSU {
    unordered_map<int, int> id;
    int cc = 0;

    void add(int i) {
        id[i] = i;
        cc++;
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
        cc--;
    }
};

class Solution {
public:
    vector<int> numIslands2(int h, int w, vector<vector<int>> &positions) {
        vector<vector<int>> a(h, vector<int>(w));
        DSU dsu;
        vector<int> res(positions.size());

        for (int i = 0; i < positions.size(); i++) {
            int y = positions[i][0];
            int x = positions[i][1];

            if (!a[y][x]) {
                a[y][x] = 1;
                dsu.add(y * w + x);

                static vector<int> dy = { -1, 0, 1, 0 };
                static vector<int> dx = { 0, 1, 0, -1 };
                
                for (int d = 0; d < dy.size(); d++) {
                    int ty = y + dy[d];
                    int tx = x + dx[d];

                    if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx])
                        dsu.merge(y * w + x, ty * w + tx);
                }
            }

            res[i] = dsu.cc;
        }

        return res;
    }
};