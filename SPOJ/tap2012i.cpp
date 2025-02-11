#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int museumCount;
    cin >> museumCount;

    if (museumCount == -1)
        return 0;

    int sum = 0, res = 0;
    for (int i = 0; i < museumCount; i++) {
        int fee;
        cin >> fee;
        sum += fee;
        res += sum % 100 == 0;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}