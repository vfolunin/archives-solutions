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

    int a, b, c;
    cin >> a >> b >> c;

    for (char c1 : { '+', '-' }) {
        for (char c2 : { '+', '-' }) {
            int res = a;
            res += c1 == '+' ? b : -b;
            res += c2 == '+' ? c : -c;

            if (res == 2020) {
                cout << a << c1 << b << c2 << c;
                return 0;
            }
        }
    }

    cout << "CORONA";
}