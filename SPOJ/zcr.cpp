#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, targetCount;
    cin >> size >> targetCount;

    vector<double> res(targetCount + 1);
    res[0] = 1;

    for (int i = 0; i < size; i++) {
        double p;
        cin >> p;

        vector<double> nextRes(targetCount + 1);
        nextRes[0] = res[0] * (1 - p);
        for (int count = 1; count <= targetCount; count++)
            nextRes[count] = res[count - 1] * p + res[count] * (1 - p);
        res.swap(nextRes);
    }

    cout << fixed << res[targetCount] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}