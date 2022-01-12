#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int beatCount;
    double seconds;
    cin >> beatCount >> seconds;

    double bpm = 60 * beatCount / seconds;
    double delta = bpm / beatCount;

    cout << fixed << bpm - delta << " " << bpm << " " << bpm + delta << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}