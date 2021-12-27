#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int aSize, bSize;
    if (!(cin >> aSize >> bSize))
        return 0;

    vector<int> a(aSize);
    for (int &x : a)
        cin >> x;

    vector<int> b(bSize);
    for (int &x : b)
        cin >> x;

    int bi = 0;
    for (int ai = 0; ai < aSize; ai++)
        if (bi < bSize && a[ai] == b[bi])
            bi++;

    cout << (bi == bSize ? "sim\n" : "nao\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}