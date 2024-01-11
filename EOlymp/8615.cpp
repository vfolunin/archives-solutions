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

    int n, l, r;
    cin >> n >> l >> r;

    cout << (l <= n && n <= r ? "IN" : "OUT");
}