#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int h, w, n;
    cin >> h >> w >> n;

    if (!h)
        return 0;

    vector<int> badR(h), badC(w);
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        badR[r] = 1;
        badC[c] = 1;
    }

    int r, c;
    cin >> r >> c;

    cout << "Case " << test << ": ";

    static int dr[] = { 0, -1, 0, 1, 0 };
    static int dc[] = { 0, 0, 1, 0, -1 };

    for (int d = 0; d < 5; d++) {
        int tr = r + dr[d];
        int tc = c + dc[d];
        if (0 <= tr && tr < h && 0 <= tc && tc < w && !badR[tr] && !badC[tc]) {
            cout << "Escaped again! More 2D grid problems!\n";
            return 1;
        }
    }

    cout << "Party time! Let's find a restaurant!\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}