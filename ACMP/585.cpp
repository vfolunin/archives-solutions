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

    double power = 1;
    for (int i = 1; 1; i++) {
        power *= 2;

        if ((int)(power + 1e-9) == n) {
            cout << i;
            return 0;
        }

        if (power > n)
            power /= 10;
    }
}