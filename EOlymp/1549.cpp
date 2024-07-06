#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int gSize, kSize, n;
    cin >> gSize >> kSize >> n;

    if (!n)
        return 0;

    cout << (kSize % 2 ? "Keka\n" : "Gared\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}