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

    string l, r;
    cin >> l >> r;

    if (l.size() == r.size())
        cout << l;
    else
        cout << min(l, "1" + string(l.size(), '0'));
}