#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n;
    if (!(cin >> n))
        return 0;

    n--;
    for (long long row = 1; 1; row++) {
        if (n >= row) {
            n -= row;
        } else {
            cout << row - n << "/" << n + 1 << "\n";
            return 1;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}