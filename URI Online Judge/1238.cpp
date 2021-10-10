#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < a.size() && i < b.size(); i++)
        cout << a[i] << b[i];

    if (a.size() > b.size())
        swap(a, b);

    cout << b.substr(a.size()) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}