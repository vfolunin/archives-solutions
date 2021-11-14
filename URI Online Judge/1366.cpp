#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    int pairCount = 0;
    for (int i = 0; i < n; i++) {
        int size, count;
        cin >> size >> count;
        pairCount += count / 2;
    }

    cout << pairCount / 2 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}