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

    for (int d = 3; d <= n; d++) {
        if (n % d == 0) {
            cout << d - 1;
            return 0;
        }
    }
}