class Solution {
    vector<vector<int>> mark(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        vector<vector<int>> marked(h, vector<int>(w));

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (y + 2 < h && a[y][x] && a[y][x] == a[y + 1][x] && a[y][x] == a[y + 2][x])
                    marked[y][x] = marked[y + 1][x] = marked[y + 2][x] = 1;
                if (x + 2 < w && a[y][x] && a[y][x] == a[y][x + 1] && a[y][x] == a[y][x + 2])
                    marked[y][x] = marked[y][x + 1] = marked[y][x + 2] = 1;
            }
        }

        return marked;
    }

    bool clear(vector<vector<int>> &a, const vector<vector<int>> &marked) {
        bool updated = 0;
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (marked[y][x]) {
                    a[y][x] = 0;
                    updated = 1;
                }
            }
        }
        return updated;
    }

    void propagate(vector<vector<int>> &a) {
        for (int x = 0; x < a[0].size(); x++) {
            for (int toY = a.size() - 1, fromY = a.size() - 1; fromY >= 0; fromY--) {
                if (a[toY][x]) {
                    toY--;
                } else if (a[fromY][x]) {
                    swap(a[toY][x], a[fromY][x]);
                    toY--;
                }
            }
        }
    }

public:
    vector<vector<int>> candyCrush(vector<vector<int>> &a) {
        while (clear(a, mark(a))) 
            propagate(a);
        return a;
    }
};