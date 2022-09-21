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

    int a, b, l, n;
    cin >> a >> b >> l >> n;

    cout << ((n - 1) * (a + b) + l) * 2 + a;
}