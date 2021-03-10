#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long height;
    if (!(cin >> height))
        return 0;

    int partCount;
    cin >> partCount;

    long long area = 0;
    for (int i = 0; i < partCount; i++) {
        long long h, w;
        cin >> h >> w;
        area += h * w;
    }

    cout << area / height << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}