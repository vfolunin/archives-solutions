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

    bool found = 0;
    for (int a = 1; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {
                if (a + b + c == sum && a != b && a != c && b != c) {
                    cout << a << b << c << " ";
                    found = 1;
                }
            }
        }
    }

    if (!found)
        cout << "No";
}