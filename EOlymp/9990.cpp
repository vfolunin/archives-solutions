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
    for (int a = 1, b = sum - 1; a <= 9; a++, b--) {
        if (0 <= b && b <= 9 && a % 2 == b % 2) {
            cout << a << b << " ";
            found = 1;
        }
    }

    if (!found)
        cout << "No";
}