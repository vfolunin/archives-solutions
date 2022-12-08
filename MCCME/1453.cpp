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

    int mod = 0;
    cin >> mod;

    int size = 1, remainder = 1 % mod;
    while (size <= mod && remainder) {
        size++;
        remainder = (remainder * 10 + 1) % mod;
    }

    cout << (remainder ? "NO" : string(size, '1'));
}