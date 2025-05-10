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

    int sum;
    cin >> sum;

    for (int num = (sum - 1) / 2, den = sum - num; num; num--, den++) {
        if (gcd(num, den) == 1) {
            cout << num << " " << den;
            return 0;
        }
    }
}