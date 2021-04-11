#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int routerCount, queryCount;
    cin >> routerCount >> queryCount;

    vector<int> x(routerCount), y(routerCount), r(routerCount);
    for (int i = 0; i < routerCount; i++)
        cin >> x[i] >> y[i] >> r[i];

    cout << "Case " << test << ":\n";
    for (int i = 0; i < queryCount; i++) {
        int qx, qy;
        cin >> qx >> qy;

        bool found = 0;
        for (int j = 0; !found && j < routerCount; j++)
            found |= (qx - x[j]) * (qx - x[j]) + (qy - y[j]) * (qy - y[j]) <= r[j] * r[j];
        
        cout << (found ? "Yes\n" : "No\n");
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