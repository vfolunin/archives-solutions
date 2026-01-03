#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    getline(cin, s);

    if (s == "  ")
        return 0;

    cout << (s == "bd" || s == "db" || s == "pq" || s == "qp" ? "Mirrored" : "Ordinary") << " pair\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << "Ready\n";
    while (solve());
}