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

    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    cout << (l1 <= r2 && l2 <= r1 ? "NO" : "YES");
}