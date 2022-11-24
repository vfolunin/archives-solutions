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

    int n;
    cin >> n;

    for (int a = 0; a < 100; a++) {
        for (int b = 0; b < 100; b++) {
            for (int c = 0; c < 100; c++) {
                for (int d = 0; d < 100; d++) {
                    if (a * a + b * b + c * c + d * d == n) {
                        if (a)
                            cout << a << " ";
                        if (b)
                            cout << b << " ";
                        if (c)
                            cout << c << " ";
                        if (d)
                            cout << d << " ";
                        return 0;
                    }
                }
            }
        }
    }
}