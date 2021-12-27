#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w, queryCount;
    if (!(cin >> h >> w >> queryCount))
        return 0;

    for (int i = 0; i < queryCount; i++) {
        int qh, qw;
        cin >> qh >> qw;

        cout << (qh <= h && qw <= w || qh <= w && qw <= h ? "Sim\n" : "Nao\n");
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}