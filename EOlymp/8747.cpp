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

    int mod;
    cin >> mod;

    int remainder = 0;
    for (int i = 1; 1; i++) {
        remainder = (remainder + i) % mod;
        if (!remainder) {
            cout << i;
            break;
        }
    }
}