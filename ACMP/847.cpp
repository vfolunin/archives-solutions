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

    string a, b;
    cin >> a >> b;

    if (a.size() != b.size()) {
        cout << "NO";
        return 0;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            cout << "NO";
            return 0;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << (a == b ? "YES" : "NO");
}