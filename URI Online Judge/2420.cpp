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

    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i)
            p[i] += p[i - 1];
    }

    cout << upper_bound(p.begin(), p.end(), p[n - 1] / 2) - p.begin() << "\n";
}