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

    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    cout << (a * x + b * y + c == 0 ? "YES" : "NO");
}