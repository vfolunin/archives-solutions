#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double s;
    if (!(cin >> s))
        return 0;

    static double f[] = {
        0.8660254037844386,
        0.4641016151377546,
        0.4330127018922193,
        0.3750152213405402
    };

    cout.precision(10);
    for (int i = 0; i < 4; i++)
        cout << fixed << f[i] * s << (i < 3 ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}