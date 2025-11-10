#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string a, b;
    cin >> a >> b;

    if (a[0] == 'E')
        return 0;

    string signs = "RSP";
    int aScore = 0, bScore = 0;

    for (int i = 0; i < a.size(); i++) {
        int ai = signs.find(a[i]);
        int bi = signs.find(b[i]);

        aScore += (ai + 1) % signs.size() == bi;
        bScore += (bi + 1) % signs.size() == ai;
    }

    cout << "P1: " << aScore << "\n";
    cout << "P2: " << bScore << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}