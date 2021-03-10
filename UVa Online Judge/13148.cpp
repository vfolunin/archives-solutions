#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

set<int> prepare() {
    set<int> res;
    for (int i = 1; i <= 21; i++)
        res.insert(i * i * i * i * i * i);
    return res;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static set<int> s = prepare();
    cout << (s.count(n) ? "Special\n" : "Ordinary\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}