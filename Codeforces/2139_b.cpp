#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, time;
    cin >> size >> time;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.rbegin(), a.rend());

    long long res = 0;
    for (int i = 0; i < time && i < a.size(); i++)
        res += 1LL * a[i] * (time - i);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}