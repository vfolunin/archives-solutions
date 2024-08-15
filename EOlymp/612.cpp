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

    int pos = 0;
    while (pos < a.size() && a[pos] == b[pos])
        pos++;

    if (pos + 1 < a.size())
        swap(a[pos], a[pos + 1]);

    cout << (a == b ? "YES" : "NO");
}