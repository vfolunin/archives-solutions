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

    vector<long long> a(3);
    int count;
    cin >> a[0] >> a[1] >> a[2] >> count;

    sort(a.begin(), a.end());

    if (a[2] == 1) {
        if (count == 6)
            cout << 1;
        else
            cout << 0;
    } else if (a[1] == 1) {
        if (count == 4)
            cout << a[2] - 2;
        else if (count == 5)
            cout << 2;
        else
            cout << 0;
    } else if (a[0] == 1) {
        if (count == 2)
            cout << (a[1] - 2) * (a[2] - 2);
        else if (count == 3)
            cout << 2 * (a[1] - 2 + a[2] - 2);
        else if (count == 4)
            cout << 4;
        else
            cout << 0;
    } else {
        if (count == 0)
            cout << (a[0] - 2) * (a[1] - 2) * (a[2] - 2);
        else if (count == 1)
            cout << 2 * ((a[0] - 2) * (a[1] - 2) + (a[0] - 2) * (a[2] - 2) + (a[1] - 2) * (a[2] - 2));
        else if (count == 2)
            cout << 4 * (a[0] - 2 + a[1] - 2 + a[2] - 2);
        else if (count == 3)
            cout << 8;
        else
            cout << 0;
    }
}