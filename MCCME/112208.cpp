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

    int mod1, rem1, mod2, rem2;
    cin >> mod1 >> rem1 >> mod2 >> rem2;

    bool found = 0;
    for (int i = 1e4; i < 1e5; i++) {
        if (i % mod1 == rem1 && i % mod2 == rem2) {
            cout << i << " ";
            found = 1;
        }
    }

    if (!found)
        cout << -1;
}