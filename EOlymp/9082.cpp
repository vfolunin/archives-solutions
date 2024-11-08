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

    int limit5 = 0, limit7 = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value == 5)
            limit5++;
        else
            limit7++;
    }

    for (int k = size; k; k--) {
        for (int k7 = k - 1, k5 = 1; k7 >= 0; k7--, k5++) {
            if (k7 <= limit7 && k5 <= limit5 && (k7 * 7 + k5 * 5) % 3 == 0) {
                cout << string(k7, '7') << string(k5, '5');
                return 0;
            }
        }
    }

    cout << "Impossible";
}