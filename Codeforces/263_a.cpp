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

    for (int y = -2; y <= 2; y++) {
        for (int x = -2; x <= 2; x++) {
            int value;
            cin >> value;

            if (value) {
                cout << abs(y) + abs(x);
                return 0;
            }
        }
    }
}