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

    long long a, b;
    cin >> a >> b;

    for (int i = 0; 1; i++) {
        if (a < b)
            swap(a, b);

        if (a % b == 0 || a > 2 * b) {
            cout << (i % 2 ? "lose" : "win");
            break;
        }

        a -= b;
    }
}