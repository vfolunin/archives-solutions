#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int limit, size;
    cin >> limit >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.rbegin(), a.rend());
    
    int res = 0;
    for (int i = 0; i < a.size() && i < limit; i++)
        res += a[i];

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}