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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool found = 0;

    for (char abSign : string("*+-/")) {
        int ab = -1e9 - 1;
        if (abSign == '+')
            ab = a + b;
        if (abSign == '-')
            ab = a - b;
        else if (abSign == '*')
            ab = a * b;
        else if (b && abSign == '/')
            ab = a / b;

        for (char cdSign : string("*+-/")) {
            int cd = -1e9 - 2;
            if (cdSign == '+')
                cd = c + d;
            else if (cdSign == '-')
                cd = c - d;
            else if (cdSign == '*')
                cd = c * d;
            else if (d && cdSign == '/')
                cd = c / d;

            if (ab == cd) {
                cout << a << " " << abSign << " " << b << " = ";
                cout << c << " " << cdSign << " " << d << "\n";
                found = 1;
            }
        }
    }

    if (!found)
        cout << "problems ahead";
}