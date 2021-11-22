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

    int res = n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        res -= x;
    }

    cout << res << "\n";
}