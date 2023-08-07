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

    int p, mod;
    cin >> p >> mod;

    long long res = 2 % mod;
    for (int i = 0; i < p; i++)
        res = res * res % mod;

    cout << res;
}