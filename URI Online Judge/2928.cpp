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

    int gap = 0, jumpCount = 0;

    for (int i = 0; i < size; i++) {
        string line;
        cin >> line;

        if (line[0] == '.') {
            gap++;
        } else if (gap) {
            if (gap <= 2) {
                jumpCount++;
                gap = 0;
            } else {
                cout << "N\n";
                return 0;
            }
        }
    }

    if (gap) {
        if (gap <= 2) {
            jumpCount++;
        } else {
            cout << "N\n";
            return 0;
        }
    }

    cout << jumpCount << "\n";
}