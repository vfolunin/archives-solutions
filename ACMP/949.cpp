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

    long long n, a, b, c;
    cin >> n >> b >> c;

    for ( ; n > 1; n--) {
        a = c - b;
        c = b;
        b = a;
    }

    cout << b << " " << c;
}