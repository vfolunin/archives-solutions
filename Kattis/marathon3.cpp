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

    vector<double> tl(size), tr(size);
    for (int i = 0; i < size; i++)
        cin >> tl[i] >> tr[i];

    double l = *min_element(tl.begin(), tl.end()), r = *min_element(tr.begin(), tr.end());
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2, p = 1;

        for (int j = 0; j < size; j++) {
            if (tr[j] <= m)
                p = 0;
            if (tl[j] < m)
                p *= (tr[j] - m) / (tr[j] - tl[j]);
        }

        if (p >= 0.5)
            l = m;
        else
            r = m;
    }

    cout << fixed << l;
}