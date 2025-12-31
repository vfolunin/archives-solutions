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

    for (int l = 1, r = n; l <= r; l++, r--) {
        cout << l << " ";
        if (l < r)
            cout << r << " ";
    }
}