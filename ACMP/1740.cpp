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

    long long n;
    cin >> n;

    if (n == 0) {
        cout << "Yes\n1 1";
        return 0;
    }

    if (n % 4 == 2) {
        cout << "No";
        return 0;
    }

    for (long long a = 1; a * a < n; a++) {
        if (n % a)
            continue;

        long long b = n / a;
        if ((b - a) % 2 == 0) {
            cout << "Yes\n" << (a + b) / 2 << " " << (b - a) / 2;
            return 0;
        }
    }

    cout << "No";
}