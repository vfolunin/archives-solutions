#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> remainders = { 192, 442, 692, 942 };
    int i = 0;
    while (i < remainders.size() && n % 1000 >= remainders[i])
        i++;

    if (i < remainders.size())
        cout << n / 1000 * 1000 + remainders[i] << "\n";
    else
        cout << n / 1000 * 1001 + remainders[0] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}