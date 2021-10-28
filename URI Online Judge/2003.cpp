#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, m;
    char colon;
    if (!(cin >> h >> colon >> m))
        return 0;

    cout << "Atraso maximo: " << max(0, h * 60 + m - 420) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}