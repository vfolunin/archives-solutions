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

    int wCount = 0;
    for (int i = 0; i < 6; i++) {
        char c;
        cin >> c;

        wCount += c == 'W';
    }

    if (wCount >= 5)
        cout << 1;
    else if (wCount >= 3)
        cout << 2;
    else if (wCount >= 1)
        cout << 3;
    else
        cout << -1;
}