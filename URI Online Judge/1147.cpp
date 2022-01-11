#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> read() {
    char y, x;
    if (!(cin >> y >> x))
        return { -1, -1 };
    return { '8' - y, x - 'a' };
}

bool solve(int test) {
    auto [ky, kx] = read();

    if (ky == -1)
        return 0;

    vector<vector<int>> a(8, vector<int>(8));
    for (int i = 0; i < 8; i++) {
        auto [py, px] = read();

        static int pdy[] = { 1, 1 };
        static int pdx[] = { -1, 1 };

        for (int d = 0; d < 2; d++) {
            int ty = py + pdy[d];
            int tx = px + pdx[d];
            if (0 <= ty && ty < 8 && 0 <= tx && tx < 8)
                a[ty][tx] = 1;
        }
    }

    static int kdy[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
    static int kdx[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

    int res = 0;
    for (int d = 0; d < 8; d++) {
        int ty = ky + kdy[d];
        int tx = kx + kdx[d];
        res += 0 <= ty && ty < 8 && 0 <= tx && tx < 8 && !a[ty][tx];
    }

    cout << "Caso de Teste #" << test << ": " << res << " movimento(s).\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}