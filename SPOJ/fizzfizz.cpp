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

    for (int i = 1; i <= n; i++) {
        int value = i, power = 0;
        while (value % 3 == 0) {
            power++;
            value /= 3;
        }

        if (power) {
            for (int j = 0; j < power; j++)
                cout << "fizz" << (j + 1 < power ? "-" : "\n");
        } else {
            cout << i << "\n";
        }
    }
}