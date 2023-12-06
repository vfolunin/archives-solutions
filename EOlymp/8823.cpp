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

    long long a = 9, b = 8;
    for (int i = 1; i < n; i++) {
        a *= 10;
        b *= 9;
    }

    cout << a - b;
}