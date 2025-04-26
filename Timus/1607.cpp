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

    int a, ad, b, bd;
    cin >> a >> ad >> b >> bd;

    while (a < b) {
        a = min(a + ad, b);
        b = max(b - bd, a);
    }

    cout << a;
}