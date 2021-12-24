#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int cellCount, runCount, runDelta;
    cin >> cellCount >> runCount >> runDelta;

    vector<double> cells(cellCount);
    for (double &cell : cells)
        cin >> cell;

    sort(cells.begin(), cells.end());

    double time = 0;
    for (int i = 0; i < cellCount; i++)
        time += 1 / (cells[i] + (i < runCount ? runDelta : 0));

    cout.precision(2);
    cout << fixed << time << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}