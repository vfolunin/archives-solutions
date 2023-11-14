#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int a, b; cin >> a >> b; )
        cout << (gcd(a, b) == 1 ? "YES\n" : "NO\n");
}