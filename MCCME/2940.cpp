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

    int v, t, mod = 109;
    cin >> v >> t;

    cout << ((v * t % mod) + mod) % mod;
}