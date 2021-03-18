#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int antCount;
    cin >> antCount;

    if (!antCount)
        return 0;

    int maxC = 0, maxV = 0;
    for (int i = 0; i < antCount; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (c > maxC) {
            maxC = c;
            maxV = a * b * c;
        } else if (c == maxC) {
            maxV = max(maxV, a * b * c);
        }
    }

    cout << maxV << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}