#include <iostream>
#include <iomanip>
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

    if (n % 4 == 0 || n % 4 == 3) {
        vector<int> a[2];

        if (n % 4 == 3) {
            a[0].push_back(n);
            n--;
        }

        for (int l = 1, r = n; l < r; l++, r--) {
            a[l % 2].push_back(l);
            a[l % 2].push_back(r);
        }

        cout << "YES\n";
        for (int i = 0; i < 2; i++) {
            cout << a[i].size() << "\n";
            for (int x : a[i])
                cout << x << " ";
            cout << "\n";
        }
    } else {
        cout << "NO";
    }
}