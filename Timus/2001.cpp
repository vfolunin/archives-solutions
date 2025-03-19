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

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    cout << a - e << " " << b - d;
}