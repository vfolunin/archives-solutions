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

    int a, b;
    cin >> a >> b;

    int l = max(a * 50 - 49, b * 70 - 69);
    int r = min(a * 50 - 1, b * 70 - 1);

    if (l <= r) {
        l = (l + 59) / 60;
        r = (r + 59) / 60;
        for (int i = l; i <= r; i++)
            cout << i << " ";
    } else {
        cout << -1;
    }
}