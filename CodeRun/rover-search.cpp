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

    int l = -1e9, r = 1e9;

    for (int i = 0; i < size; i++) {
        int x, limit;
        cin >> x >> limit;

        l = max(l, x - limit);
        r = min(r, x + limit);
    }

    cout << (l <= r ? r : -1);
}