#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double p1;
    int guessCount;
    if (!(cin >> p1 >> guessCount))
        return 0;

    double p2 = 1 - p1;

    for (int i = 0; i < guessCount; i++) {
        char type;
        double p;
        cin >> type >> p;

        if (type == 'R') {
            p1 *= p;
            p2 *= 1 - p;
        } else {
            p1 *= 1 - p;
            p2 *= p;
        }
    }

    cout.precision(6);
    cout << fixed << p1 / (p1 + p2) << " " << p2 / (p1 + p2) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}