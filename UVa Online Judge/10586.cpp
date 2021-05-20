#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int ap, bp;
    cin >> ap >> bp;

    if (ap < 0 && bp < 0)
        return 0;

    vector<int> a(ap + 1);
    for (int &coeff : a)
        cin >> coeff;


    for (int power = ap; power >= bp; power--) {
        a[power - bp] -= a[power];
        a[power] = 0;
    }

    while (a.size() > 1 && !a.back())
        a.pop_back();

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << (i + 1 < a.size() ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}