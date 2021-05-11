#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int pointCount;
    cin >> pointCount;

    vector<int> x(pointCount), y(pointCount), z(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> x[i] >> y[i] >> z[i];

    int res = 0;
    for (int kx : {-1, 1}) {
        for (int ky : {-1, 1}) {
            for (int kz : {-1, 1}) {
                int minVal = 1e9, maxVal = -1e9;
                for (int i = 0; i < pointCount; i++) {
                    minVal = min(minVal, kx * x[i] + ky * y[i] + kz * z[i]);
                    maxVal = max(maxVal, kx * x[i] + ky * y[i] + kz * z[i]);
                }
                res = max(res, maxVal - minVal);
            }
        }
    }

    cout << "Case #" << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}