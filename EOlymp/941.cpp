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
    n = abs(n);

    double sum = 0, product = 1;
    while (n) {
        sum += n % 10;
        product *= n % 10;
        n /= 10;
    }

    cout << product - sum;
}