#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDivisorCount(int n) {
    int res = 0;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            res++;
            res += d * d != n;
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, limit;
    cin >> size >> limit;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << (getDivisorCount(y * size + x + 1) <= limit ? "*" : ".");
        cout << "\n";
    }
}