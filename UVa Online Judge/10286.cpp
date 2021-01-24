#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long double size;
    if (!(cin >> size))
        return 0;

    static const long double FACTOR = 1.067395681711181875;

    cout.precision(10);
    cout << fixed << FACTOR * size << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}