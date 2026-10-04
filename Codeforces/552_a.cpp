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

    long long res = 0;
    for (int i = 0; i < size; i++) {
        int xa, ya, xb, yb;
        cin >> xa >> ya >> xb >> yb;

        res += (xb - xa + 1) * (yb - ya + 1);
    }

    cout << res;
}