#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Board {
    vector<string> a;

    Board() : a(4, string(4, '.')) {}

    int code() {
        static string s = ".xo";
        int code = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                code = code * 3 + s.find(a[i][j]);
        return code;
    }

    int isGameover() {
        bool hasFree = 0;
        for (int i = 0; i < 4; i++) {
            if (a[i][0] != '.' && a[i][0] == a[i][1] && a[i][0] == a[i][2] && a[i][0] == a[i][3])
                return a[i][0] == 'x' ? 1 : 2;
            if (a[0][i] != '.' && a[0][i] == a[1][i] && a[0][i] == a[2][i] && a[0][i] == a[3][i])
                return a[0][i] == 'x' ? 1 : 2;
            hasFree |= a[i].find('.') != -1;
        }
        if (a[0][0] != '.' && a[0][0] == a[1][1] && a[0][0] == a[2][2] && a[0][0] == a[3][3])
            return a[0][0] == 'x' ? 1 : 2;
        if (a[0][3] != '.' && a[0][3] == a[1][2] && a[0][3] == a[2][1] && a[0][3] == a[3][0])
            return a[0][3] == 'x' ? 1 : 2;
        return hasFree ? 0 : 3;
    }

    char player() {
        int free = 0;
        for (int i = 0; i < 4; i++)
            free += count(a[i].begin(), a[i].end(), '.');
        return free % 2 == 0 ? 'x' : 'o';
    }
};

int rec(Board &b) {
    static vector<int> memo(43046721);
    int code = b.code();
    if (memo[code])
        return memo[code];

    char p = b.player();

    int gameover = b.isGameover();
    if (gameover == 1 && p == 'x' || gameover == 2 && p == 'o') 
        return memo[code] = 1;
    if (gameover == 1 && p == 'o' || gameover == 2 && p == 'x')
        return memo[code] = 2;
    if (gameover == 3)
        return memo[code] = 3;

    bool canMakeDraw = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (b.a[i][j] != '.')
                continue;

            b.a[i][j] = p;
            int r = rec(b);
            b.a[i][j] = '.';

            if (r == 2)
                return memo[code] = 1;

            canMakeDraw |= r == 3;
        }
    }

    return memo[code] = (canMakeDraw ? 3 : 2);
}

bool solve() {
    char c;
    cin >> c;

    if (c == '$')
        return 0;

    Board b;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> b.a[i][j];

    if (rec(b) != 1) {
        cout << "#####\n";
    } else {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (b.a[i][j] == '.') {
                    b.a[i][j] = 'x';
                    if (rec(b) == 2) {
                        cout << "(" << i << "," << j << ")\n";
                        return 1;
                    }
                    b.a[i][j] = '.';
                }
            }
        }
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}