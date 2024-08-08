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

    int type;
    cin >> type;

    int res = 0;
    for (int a = 1; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            if (type == 1) {
                res += a > b;
            } else if (type == 2) {
                res += a < b;
            } else if (type == 3) {
                res += a % 2 == b % 2;
            } else if (type == 4) {
                if (a == b)
                    res += a * 10 + b;
            } else if (type == 5) {
                if (a % 2 == 0 && b % 2 == 0)
                    res += a * 10 + b;
            } else {
                if (a % 2 && b % 2)
                    res += a * 10 + b;
            }
        }
    }

    cout << res;
}