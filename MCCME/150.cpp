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

    for (int a = 0; a * a * a <= n; a++) {
        for (int b = 0; a * a * a + b * b * b <= n; b++) {
            if (a * a * a + b * b * b == n) {
                cout << a << " " << b;
                return 0;
            }
        }
    }

    cout << "impossible";
}