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

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int l, r, type;
    cin >> l >> r >> type;
    l--;
    r--;

    sort(a.begin() + l, a.begin() + r + 1, [&](int lhs, int rhs) {
        return type == 1 ? lhs < rhs : lhs > rhs;
    });

    for (int value : a)
        cout << value << " ";
}