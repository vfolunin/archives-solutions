#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    char type;
    int delta, h, m;
    cin >> type >> delta >> h >> m;

    int t = h * 60 + m + (type == 'F' ? 1 : -1) * delta;
    t = (t % 1440 + 1440) % 1440;

    cout << t / 60 << " " << t % 60 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}