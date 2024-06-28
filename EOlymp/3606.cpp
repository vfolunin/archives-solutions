#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount, distLimit;
    cin >> pointCount >> distLimit;

    vector<int> x(pointCount);
    vector<int> y(pointCount);
    for (int i = 0; i < pointCount; i++)
        cin >> x[i] >> y[i];

    int res = 0;
    for (int i = 0; i < pointCount; i++) {
        for (int j = i + 1; j < pointCount; j++) {
            int dx = abs(x[i] - x[j]);
            int dy = abs(y[i] - y[j]);
            res += dx * dx + dy * dy <= distLimit * distLimit;
        }
    }

    cout << res;
}