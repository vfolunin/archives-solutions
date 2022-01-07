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

    vector<int> a(size);
    for (int &x : a) {
        cin >> x;
        x--;
    }

    int res = 0;
    for (int i = 0; i < size; i++) {
        while (a[i] != i) {
            res++;
            swap(a[i], a[a[i]]);
        }
    }

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