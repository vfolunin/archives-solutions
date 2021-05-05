#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int stationCount;
    cin >> stationCount;

    vector<int> fuel(stationCount);
    for (int &x : fuel)
        cin >> x;

    vector<int> dist(stationCount);
    for (int &x : dist)
        cin >> x;

    cout << "Case " << test << ": ";

    int from = 0;
    while (1) {
        int curFuel = 0, ok = 1;

        for (int i = 0; i < stationCount; i++) {
            curFuel += fuel[(from + i) % stationCount];
            if (curFuel < dist[(from + i) % stationCount]) {
                if ((from + i + 1) % stationCount <= from) {
                    cout << "Not possible\n";
                    return;
                }
                from = (from + i + 1) % stationCount;
                ok = 0;
                break;
            }
            curFuel -= dist[(from + i) % stationCount];
        }

        if (ok) {
            cout << "Possible from station " << from + 1 << "\n";
            return;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}