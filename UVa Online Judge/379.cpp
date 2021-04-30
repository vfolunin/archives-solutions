#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const vector<int> LAST = { 3, 6, 13, 20, 27, 30, 33 };
const vector<int> LAST_J = { 4, 4, 6, 6, 6, 4, 4 };

pair<int, int> coords(int n) {
    int i = lower_bound(LAST.begin(), LAST.end(), n) - LAST.begin();
    int j = LAST_J[i] - (LAST[i] - n);
    return { i, j };
}

int num(int i, int j) {
    return LAST[i] - (LAST_J[i] - j);
}

void solve() {
    vector<string> a(7, string(7, ' '));
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            if ((i < 2 || i > 4) && (j < 2 || j > 4))
                a[i][j] = '#';

    while (1) {
        int n;
        cin >> n;

        if (!n)
            break;

        auto [i, j] = coords(n);
        a[i][j] = 'X';
    }

    while (1) {
        int bestToI = -1, bestToJ = -1;
        int bestMidI = -1, bestMidJ = -1;
        int bestFromI = -1, bestFromJ = -1;

        for (int toI = 0; toI < 7; toI++) {
            for (int toJ = 0; toJ < 7; toJ++) {
                if (a[toI][toJ] != ' ')
                    continue;

                static vector<int> di = { -1, 0, 1, 0 };
                static vector<int> dj = { 0, 1, 0, -1 };

                for (int d = 0; d < 4; d++) {
                    int fromI = toI + di[d] * 2, fromJ = toJ + dj[d] * 2;
                    int midI = toI + di[d], midJ = toJ + dj[d];
                    if (0 <= fromI && fromI < 7 && 0 <= fromJ && fromJ < 7 && a[fromI][fromJ] == 'X' && a[midI][midJ] == 'X') {
                        if (bestToI * 7 + bestToJ < toI * 7 + toJ ||
                            bestToI * 7 + bestToJ == toI * 7 + toJ && bestFromI * 7 + bestFromJ < fromI * 7 + fromJ) {
                            bestToI = toI;
                            bestToJ = toJ;
                            bestMidI = midI;
                            bestMidJ = midJ;
                            bestFromI = fromI;
                            bestFromJ = fromJ;
                        }
                    }
                }
            }
        }

        if (bestToI == -1)
            break;

        a[bestFromI][bestFromJ] = ' ';
        a[bestMidI][bestMidJ] = ' ';
        a[bestToI][bestToJ] = 'X';
    }

    int res = 0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            if (a[i][j] == 'X')
                res += num(i, j);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << "HI Q OUTPUT\n";
    for (int i = 0; i < n; i++)
        solve();
    cout << "END OF OUTPUT\n";
}