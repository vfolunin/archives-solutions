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

    int n, l, r;
    cin >> n >> l >> r;

    for (int i = 1; i <= n; i++) {
        if (l <= i && i <= r)
            cout << r - (i - l) << " ";
        else
            cout << i << " ";
    }

    cout << "END.";
}