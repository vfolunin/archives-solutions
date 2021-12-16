#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long time;
    cin >> time;

    if (!time)
        return 0;

    cout << "Brasil " << time / 90 << " x ";
    cout << "Alemanha " << (time * 7 + 89) / 90 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}