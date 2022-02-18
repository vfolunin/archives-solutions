#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int childCount;
    cin >> childCount;

    long long remainder = 0;
    for (int i = 0; i < childCount; i++) {
        long long candyCount;
        cin >> candyCount;
        remainder += candyCount;
        remainder %= childCount;
    }
    
    cout << (remainder ? "NO\n" : "YES\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}