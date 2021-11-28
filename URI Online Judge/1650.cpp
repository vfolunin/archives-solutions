#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int height, width, white;
    cin >> height >> width >> white;

    if (!height && !width)
        return 0;

    long long res = 0;
    if (!white) {
        res += (height - 7) / 2;
        width--;
    }
    res += ((height - 6) / 2) * ((width - 6) / 2);
    res += ((height - 7) / 2) * ((width - 7) / 2);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}