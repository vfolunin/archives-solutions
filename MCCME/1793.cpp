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

    int size, x, a, b, mod;
    cin >> size >> x >> a >> b >> mod;

    vector<int> last(size + 1, 1e9);
    last[0] = -1e9;

    for (int i = 0; i < size; i++) {
        *lower_bound(last.begin(), last.end(), x) = x;
        x = (a * x + b) % mod;
    }

    int res = size;
    while (last[res] == 1e9)
        res--;

    cout << res;
}