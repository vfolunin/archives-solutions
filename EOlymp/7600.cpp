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
            for (int c = 0; c <= 9; c++) {
                if (type == 1) {
                    if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
                        res += a * 100 + b * 10 + c;
                } else if (type == 2) {
                    res += a < b && b < c;
                } else if (type == 3) {
                    if (a % 2 && b % 2 && c % 2)
                        res += a * 100 + b * 10 + c;
                } else if (type == 4) {
                    res += a > b && b > c;
                } else if (type == 5) {
                    if (a * a * a + b * b * b + c * c * c == a * 100 + b * 10 + c)
                        res += a * 100 + b * 10 + c;
                } else {
                    res += a != b && a != c && b != c;
                }
            }
        }
    }

    cout << res;
}