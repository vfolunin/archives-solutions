class Solution {
    vector<vector<char>> a;
    vector<vector<vector<int>>> block;
    vector<vector<int>> possibleCount;
    set<tuple<int, int, int>> possibleCounts;

    void mark(int y, int x, int value) {
        if (!block[y][x][value]) {
            possibleCounts.erase({ possibleCount[y][x], y, x });
            possibleCount[y][x]--;
            possibleCounts.insert({ possibleCount[y][x], y, x });
        }
        block[y][x][value]++;
    }

    void unmark(int y, int x, int value) {
        block[y][x][value]--;
        if (!block[y][x][value]) {
            possibleCounts.erase({ possibleCount[y][x], y, x });
            possibleCount[y][x]++;
            possibleCounts.insert({ possibleCount[y][x], y, x });
        }
    }

    void set(int y, int x, int value) {
        a[y][x] = '0' + value;
        for (int i = 0; i < 9; i++) {
            mark(i, x, value);
            mark(y, i, value);
            mark(y / 3 * 3 + i / 3, x / 3 * 3 + i % 3, value);
        }
        for (int value = 1; value <= 9; value++)
            mark(y, x, value);
    }

    void unset(int y, int x, int value) {
        a[y][x] = '.';
        for (int i = 0; i < 9; i++) {
            unmark(i, x, value);
            unmark(y, i, value);
            unmark(y / 3 * 3 + i / 3, x / 3 * 3 + i % 3, value);
        }
        for (int value = 1; value <= 9; value++)
            unmark(y, x, value);
    }
    
    bool allSet() {
        for (int y = 0; y < 9; y++)
            for (int x = 0; x < 9; x++)
                if (a[y][x] == '.')
                    return 0;
        return 1;
    }

    bool rec() {
        auto it = possibleCounts.begin();
        while (it != possibleCounts.end() && !get<0>(*it))
            it++;

        if (it == possibleCounts.end())
            return allSet();

        auto [_, y, x] = *it;
        for (int value = 1; value <= 9; value++) {
            if (!block[y][x][value]) {
                set(y, x, value);
                if (rec())
                    return 1;
                unset(y, x, value);
            }
        }

        return 0;
    }

public:
    Solution() :
        block(9, vector<vector<int>>(9, vector<int>(10))),
        possibleCount(9, vector<int>(9, 9)) {}

    void solveSudoku(vector<vector<char>> &board) {
        a = board;
        for (int y = 0; y < 9; y++)
            for (int x = 0; x < 9; x++)
                if (a[y][x] != '.')
                    set(y, x, a[y][x] - '0');

        rec();
        board = a;
    }
};