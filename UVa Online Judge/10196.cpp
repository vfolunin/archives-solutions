#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool checkR(const vector<string> &a, int y, int x, char target) {
    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };
    for (int d = 0; d < 4; d++) {
        for (int step = 1; 1; step++) {
            int ty = y + dy[d] * step, tx = x + dx[d] * step;
            if (ty < 0 || ty > 7 || tx < 0 || tx > 7)
                break;
            if (a[ty][tx] == target)
                return 1;
            if (a[ty][tx] != '.')
                break;
        }
    }
    return 0;
}

bool checkB(const vector<string> &a, int y, int x, char target) {
    static int dy[] = { -1, -1, 1, 1 };
    static int dx[] = { -1, 1, -1, 1 };
    for (int d = 0; d < 4; d++) {
        for (int step = 1; 1; step++) {
            int ty = y + dy[d] * step, tx = x + dx[d] * step;
            if (ty < 0 || ty > 7 || tx < 0 || tx > 7)
                break;
            if (a[ty][tx] == target)
                return 1;
            if (a[ty][tx] != '.')
                break;
        }
    }
    return 0;
}

bool checkQ(const vector<string> &a, int y, int x, char target) {
    return checkR(a, y, x, target) || checkB(a, y, x, target);
}

bool checkN(const vector<string> &a, int y, int x, char target) {
    static int dy[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
    static int dx[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
    for (int d = 0; d < 8; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (ty < 0 || ty > 7 || tx < 0 || tx > 7)
            continue;
        if (a[ty][tx] == target)
            return 1;
    }
    return 0;
}

bool checkP(const vector<string> &a, int y, int x, char target) {
    static int dy[][2] = { { -1, -1 }, { 1, 1 } };
    static int dx[][2] = { { -1, 1 }, { -1, 1 } };
    for (int d = 0; d < 2; d++) {
        int ty = y + dy[a[y][x] == 'p'][d], tx = x + dx[a[y][x] == 'p'][d];
        if (ty < 0 || ty > 7 || tx < 0 || tx > 7)
            continue;
        if (a[ty][tx] == target)
            return 1;
    }
    return 0;
}

bool solve(int test) {
    vector<string> a(8);
    for (string &row : a)
        cin >> row;

    if (count(a.begin(), a.end(), "........") == 8)
        return 0;

    bool black = 0, white = 0;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (a[y][x] == 'Q')
                black |= checkQ(a, y, x, 'k');
            if (a[y][x] == 'R')
                black |= checkR(a, y, x, 'k');
            if (a[y][x] == 'B')
                black |= checkB(a, y, x, 'k');
            if (a[y][x] == 'N')
                black |= checkN(a, y, x, 'k');
            if (a[y][x] == 'P')
                black |= checkP(a, y, x, 'k');

            if (a[y][x] == 'q')
                white |= checkQ(a, y, x, 'K');
            if (a[y][x] == 'r')
                white |= checkR(a, y, x, 'K');
            if (a[y][x] == 'b')
                white |= checkB(a, y, x, 'K');
            if (a[y][x] == 'n')
                white |= checkN(a, y, x, 'K');
            if (a[y][x] == 'p')
                white |= checkP(a, y, x, 'K');
        }
    }

    cout << "Game #" << test << ": ";
    if (black)
        cout << "black";
    else if (white)
        cout << "white";
    else
        cout << "no";
    cout << " king in check.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}