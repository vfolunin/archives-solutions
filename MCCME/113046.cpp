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

    int sum;
    cin >> sum;

    for (int a = 0; 4 * a * a <= sum; a++) {
        for (int b = a; a * a + 3 * b * b <= sum; b++) {
            for (int c = b; a * a + b * b + 2 * c * c <= sum; c++) {
                for (int d = c; a * a + b * b + c * c + d * d <= sum; d++) {
                    if (a * a + b * b + c * c + d * d == sum) {
                        cout << a << " " << b << " " << c << " " << d;
                        return 0;
                    }
                }
            }
        }
    }
}