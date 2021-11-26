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

    int p = 0;
    for (int k = 1; k < n; k *= 2) {
        p += 2;
        n -= k;
    }

    cout << (1LL << p) << "\n";
}