#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int a, b, c, d, l;
    cin >> a >> b >> c >> d >> l;

    if (!a && !b && !c && !d && !l)
        return 0;

    int res = 0;
    for (int i = 0; i <= l; i++)
        res += (a * i * i + b * i + c) % d == 0;
    
    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}