#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;

    vector<int> sum(2);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int degree;
            cin >> degree;

            if (degree != -1)
                sum[(i + j) % 2] += degree;
        }
    }

    cout << abs(sum[0] - sum[1]) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}