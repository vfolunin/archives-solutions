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

    cout << (l + (a + b) * (n - 1)) * 2 + a;
}