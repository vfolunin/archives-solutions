#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getCount(vector<int> have) {
    for (int i = 0, need = 1; 1; i++, need *= 2) {
        if (have[i % 2] >= need)
            have[i % 2] -= need;
        else
            return i;
    }
}

void solve() {
    int a, b;
    cin >> a >> b;

    cout << max(getCount({ a, b }), getCount({ b, a })) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}