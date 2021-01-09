#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int dayCount, partyCount;
    cin >> dayCount >> partyCount;

    vector<int> hartal(partyCount);
    for (int &h : hartal)
        cin >> h;

    int res = 0;
    for (int day = 1; day <= dayCount; day++) {
        if (day % 7 == 6 || day % 7 == 0)
            continue;
        for (int h : hartal) {
            if (day % h == 0) {
                res++;
                break;
            }
        }
    }

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