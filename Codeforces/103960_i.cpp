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

    for (int i = 0; i < 8; i++) {
        int value;
        cin >> value;

        if (value == 9) {
            cout << "F\n";
            return 0;
        }
    }

    cout << "S\n";
}