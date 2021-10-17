#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            cout << i + 1 << "\n";
            return 0;
        }
    }

    cout << "0\n";
    return 0;
}