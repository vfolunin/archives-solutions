#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, sum, limit;
    cin >> size >> sum >> limit;

    if (abs(sum) > size * limit)
        cout << "-1\n";
    else
        cout << (abs(sum) + limit - 1) / limit << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}