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

    int size, num;
    cin >> size >> num;

    int den = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        den = gcd(den, value);
    }

    cout << (num % den ? "NO" : "YES");
}