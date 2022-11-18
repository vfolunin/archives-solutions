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

    int n;
    cin >> n;

    for (int i = (1 << n) - 1; i >= 0; i--) {
        for (int bit = n - 1; bit >= 0; bit--)
            cout << ((i >> bit) & 1);
        cout << "\n";
    }
}