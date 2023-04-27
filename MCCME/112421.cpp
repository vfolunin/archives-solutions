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

    vector<int> count(10);
    for (char c; cin >> c; )
        if (isdigit(c))
            count[c - '0']++;

    int startDigit = 0;
    for (int digit = 1; digit < count.size(); digit++) {
        if (count[digit] >= 2) {
            count[digit] -= 2;
            startDigit = digit;
            break;
        }
    }

    if (!startDigit) {
        cout << 0;
        return 0;
    }

    cout << startDigit;

    for (int digit = 0; digit < count.size(); digit++)
        cout << string(count[digit] / 2, digit + '0');

    for (int digit = 0; digit < count.size(); digit++) {
        if (count[digit] % 2) {
            cout << (char)(digit + '0');
            break;
        }
    }

    for (int digit = count.size() - 1; digit >= 0; digit--)
        cout << string(count[digit] / 2, digit + '0');

    cout << startDigit;
}