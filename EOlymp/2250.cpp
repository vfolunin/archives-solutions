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

    if (a * b == c) {
        cout << 0;
        return 0;
    }

    for (int i = max(a, b) + 1; i <= 1e8; i++) {
        if (a * b % i == c) {
            cout << i;
            return 0;
        }
    }

    cout << 1;
}