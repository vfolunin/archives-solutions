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

    int n, base;
    cin >> n >> base;

    int sum = 0, product = 1;
    while (n) {
        sum += n % base;
        product *= n % base;
        n /= base;
    }

    cout << product - sum;
}