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

    multiset<int> deltas;
    long long res = 0;

    for (int i = 0; i < 2 * size; i++) {
        int a, b;
        cin >> a >> b;

        deltas.insert(b - a);
        res += a;
    }

    for (int i = 0; i < size; i++) {
        res += *prev(deltas.end());
        deltas.erase(prev(deltas.end()));
    }

    cout << res;
}