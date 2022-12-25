#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    vector<int> res(2);

    for (int d = 1; d * d <= a; d++) {
        if (a % d)
            continue;

        if (b % d == 0)
            res[d % 2] = max(res[d % 2], d);

        if (b % (a / d) == 0)
            res[(a / d) % 2] = max(res[(a / d) % 2], a / d);
    }

    cout << res[0] << " " << res[1];
}