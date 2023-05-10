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

    int value;
    cin >> value;

    for (int bit = 30; bit >= 0; bit--) {
        if (value & (1 << bit)) {
            if (bit % 2)
                cout << (1 << (bit - 1)) << " " << (1 << (bit - 1)) << " ";
            else
                cout << (1 << bit) << " ";
        }
    }
}