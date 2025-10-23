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

    int a, mod;
    cin >> a >> mod;

    for (int b = 1; b < mod; b++) {
        if (a * b % mod == 1) {
            cout << b;
            return 0;
        }
    }

    cout << "No such integer exists.";
}