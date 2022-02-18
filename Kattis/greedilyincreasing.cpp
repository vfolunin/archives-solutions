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

    vector<int> gis;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (gis.empty() || gis.back() < x)
            gis.push_back(x);
    }

    cout << gis.size() << "\n";
    for (int x : gis)
        cout << x << " ";
}