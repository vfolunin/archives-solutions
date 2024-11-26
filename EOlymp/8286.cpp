#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int syllableCount(int n) {
    if (n == 0)
        return 1;
    if (n == 1000)
        return 3;

    vector<int> ones = { 0, 2, 1, 1, 3, 1, 1, 1, 2, 2 };
    vector<int> tens = { 0, 2, 2, 2, 2, 3, 3, 3, 4, 4 };
    vector<int> elevens = { 2, 4, 3, 3, 4, 3, 3, 3, 4, 4 };
    vector<int> hundreds = { 0, 1, 2, 2, 4, 2, 2, 2, 3, 3 };
    int res = 0;

    if (n >= 100) {
        res += hundreds[n / 100];
        n %= 100;
    }

    if (n / 10 == 1) {
        res += elevens[n % 10];
    } else {
        if (n / 10)
            res += tens[n / 10];
        res += ones[n % 10];
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << syllableCount(n);
}