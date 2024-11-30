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

    int size;
    cin >> size;

    vector<vector<double>> a(2, vector<double>(size));
    for (int i = 0; i < size; i++)
        cin >> a[0][i] >> a[1][i];

    set<int> res;
    for (int round = 0; round < 2; round++) {
        vector<double> &cur = a[round], &other = a[round ^ 1];

        for (int i = 0; i < size; i++) {
            double l = 1, r = 100 / *max_element(cur.begin(), cur.end());
            for (int j = 0; j < size; j++) {
                if (cur[i] < cur[j])
                    r = min(r, (other[j] - other[i]) / (cur[i] - cur[j]));
                else if (cur[i] > cur[j])
                    l = max(l, (other[j] - other[i]) / (cur[i] - cur[j]));
            }

            if (l <= r + 1e-9) {
                bool ok = 1;
                for (int j = 0; ok && j < size; j++)
                    ok &= l * cur[i] + other[i] >= l * cur[j] + other[j] - 1e-9;
                if (ok)
                    res.insert(i);
            }
        }
    }

    cout << res.size() << "\n";
    for (int index : res)
        cout << index + 1 << " ";
}