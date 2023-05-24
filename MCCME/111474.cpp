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

    if (value < 10) {
        cout << 1 << value;
        return 0;
    }

    string res;
    for (int d = 9; d > 1; d--) {
        while (value % d == 0) {
            value /= d;
            res += d + '0';
        }
    }

    if (value == 1)
        cout << string(res.rbegin(), res.rend());
    else
        cout << "No solution";
}