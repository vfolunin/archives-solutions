#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<int> a(size), has(2);
    for (int &value : a) {
        cin >> value;
        has[value % 2] = 1;
    }

    if (has[0] && has[1])
        sort(a.begin(), a.end());

    for (int value : a)
        cout << value << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}