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

    int a, b, c, x;
    cin >> a >> b >> c >> x;

    cout << (a * x * x + b * x + c ? "NO" : "YES");
}