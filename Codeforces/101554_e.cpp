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

    int l = 0;
    while (l < a.size() && l < b.size() && a[l] == b[l])
        l++;

    if (l == a.size() || l == b.size()) {
        cout << max((int)b.size() - (int)a.size(), 0);
        return 0;
    }

    int r = 0;
    while (r < a.size() && r < b.size() && a[a.size() - 1 - r] == b[b.size() - 1 - r])
        r++;

    cout << max((int)b.size() - l - r, 0);
}