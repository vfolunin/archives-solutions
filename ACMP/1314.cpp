#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &a, vector<int> &b, vector<int> &c) {
    return a[0] + b[0] <= c[0] && max(a[1], b[1]) <= c[1] && max(a[2], b[2]) <= c[2] ||
        max(a[0], b[0]) <= c[0] && a[1] + b[1] <= c[1] && max(a[2], b[2]) <= c[2] ||
        max(a[0], b[0]) <= c[0] && max(a[1], b[1]) <= c[1] && a[2] + b[2] <= c[2];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a(3);
    for (int &value : a)
        cin >> value;

    vector<int> b(3);
    for (int &value : b)
        cin >> value;

    vector<int> c(3);
    for (int &value : c)
        cin >> value;

    if (can(a, b, c)) {
        cout << "YES";
        return 0;
    }

    swap(a[0], a[1]);

    if (can(a, b, c)) {
        cout << "YES";
        return 0;
    }

    swap(b[0], b[1]);

    if (can(a, b, c)) {
        cout << "YES";
        return 0;
    }

    swap(a[0], a[1]);

    if (can(a, b, c))
        cout << "YES";
    else
        cout << "NO";
}