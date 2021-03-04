#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int instrumentCount, studentCount;
    cin >> instrumentCount >> studentCount;

    vector<int> top(instrumentCount);
    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < instrumentCount; j++) {
            int p;
            cin >> p;
            if (p == 1)
                top[j]++;
        }
    }

    long long res = 1;
    for (int p : top)
        if (p)
            res *= p;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}