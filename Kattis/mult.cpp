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

    int d = 0;
    for (int i = 0; i < n; i++) {
        if (!d) {
            cin >> d;
            continue;
        }

        int x;
        cin >> x;

        if (x % d == 0) {
            cout << x << "\n";
            d = 0;
        }
    }
}