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

    int a, b, area;
    cin >> a >> b >> area;

    if (a > b)
        swap(a, b);

    for (int d = 1; d * d <= area; d++) {
        if (area % d)
            continue;

        if (a + area / d == b + d) {
            cout << b + d;
            return 0;
        }
    }

    cout << -1;
}