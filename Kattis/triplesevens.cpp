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

    int size;
    cin >> size;

    for (int y = 0; y < 3; y++) {
        bool has7 = 0;

        for (int x = 0; x < size; x++) {
            int value;
            cin >> value;

            has7 |= value == 7;
        }

        if (!has7) {
            cout << 0;
            return 0;
        }
    }

    cout << 777;
}