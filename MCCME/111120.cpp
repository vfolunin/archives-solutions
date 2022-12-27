#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int num, den;
    cin >> num >> den;

    int d = gcd(num, den);
    num /= d;
    den /= d;

    if (den < 0) {
        num *= -1;
        den *= -1;
    }

    cout << num << " " << den;
}