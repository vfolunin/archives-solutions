#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("fraction.in", "r", stdin);
    freopen("fraction.out", "w", stdout);

    int sum;
    cin >> sum;

    int num = sum / 2, den = sum - num;
    while (gcd(num, den) > 1) {
        num--;
        den++;
    }

    cout << num << " " << den;
}