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

    int res = 0;

    while (1) {
        if (cin.peek() == ',')
            cin.ignore();

        int value;
        if (!(cin >> value))
            break;

        res += value;
    }

    cout << res;
}