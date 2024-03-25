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

    int r, mod;
    cin >> r >> mod;

    int remainder = r % mod;
    while (remainder) {
        r++;
        for (char c : to_string(r))
            remainder = (remainder * 10 + c - '0') % mod;
    }

    cout << r;
}