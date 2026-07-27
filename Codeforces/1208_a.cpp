#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<int> a(3);
    int index;
    cin >> a[0] >> a[1] >> index;

    a[2] = a[0] ^ a[1];

    cout << a[index % 3] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount = 1;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}