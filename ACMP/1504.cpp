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

    int size, mod;
    cin >> size >> mod;

    if (size == 1) {
        if (mod < 10)
            cout << mod;
        else
            cout << "NO";
        return 0;
    }

    int remainder = 0;
    for (int i = 0; i < size - 1; i++) {
        cout << "1";
        remainder = (remainder * 10 + 1) % mod;
    }

    cout << (mod - remainder * 10 % mod) % mod;
}