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

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        if (n % 2) {
            cout << 5;
            return 0;
        }

        n /= 2;
    }

    cout << n % 10;
}