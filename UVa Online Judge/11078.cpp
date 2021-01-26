#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int studentCount;
    cin >> studentCount;

    vector<int> studentIq(studentCount), maxIq(studentCount);
    for (int i = 0; i < studentCount; i++) {
        cin >> studentIq[i];
        if (!i || studentIq[i] > maxIq[i - 1])
            maxIq[i] = studentIq[i];
        else
            maxIq[i] = maxIq[i - 1];
    }

    int maxDiff = -1e9;
    for (int i = 1; i < studentCount; i++)
        maxDiff = max(maxDiff, maxIq[i - 1] - studentIq[i]);

    cout << maxDiff << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}