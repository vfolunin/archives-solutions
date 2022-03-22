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

    int a, b;
    string code;
    cin >> a >> b >> code;

    int resC = 0, resD = 0;

    for (int c = 1; c <= 9; c++) {
        if (c == a || c == b)
            continue;

        for (int d = c + 1; d <= 9; d++) {
            if (d == a || d == b)
                continue;

            vector<int> curDigits = { a, b, c, d };
            sort(curDigits.begin(), curDigits.end());

            string curCode;
            for (int digit : curDigits)
                curCode += (digit == a || digit == b ? "A" : "B");

            if (curCode != code)
                continue;

            if (resC) {
                cout << -1;
                return 0;
            }

            resC = c;
            resD = d;
        }
    }

    if (resC)
        cout << resC << " " << resD;
    else
        cout << -1;
}