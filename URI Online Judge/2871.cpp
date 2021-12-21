#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w;
    if (!(cin >> h >> w))
        return 0;

    int sum = 0;
    for (int i = 0; i < h * w; i++) {
        int x;
        cin >> x;
        sum += x;
    }

    cout << sum / 60 << " saca(s) e " << sum % 60 << " litro(s)\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}