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

    int k50, k70;
    cin >> k50 >> k70;

    int l = max(k50 * 50 - 49, k70 * 70 - 69);
    int r = min(k50 * 50 - 1, k70 * 70 - 1);

    set<int> res;
    for (int i = l; i <= r; i++)
        res.insert((i + 59) / 60);

    if (!res.empty()) {
        for (int value : res)
            cout << value << " ";
    } else {
        cout << -1;
    }
}