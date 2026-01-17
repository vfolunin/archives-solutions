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
    for (int i = 0; i < 10; i++) {
        int value;
        cin >> value;

        if (res + value >= 100) {
            if (abs(res - 100) >= abs(res + value - 100))
                res += value;
            break;
        }

        res += value;
    }

    cout << res;
}