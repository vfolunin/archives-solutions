#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

pair<int, int> getFractionPartSizes(int den) {
    int den2 = 0;
    while (den % 2 == 0) {
        den /= 2;
        den2++;
    }

    int den5 = 0;
    while (den % 5 == 0) {
        den /= 5;
        den5++;
    }

    int prefixSize = max(den2, den5), periodSize = den > 1;

    if (periodSize) {
        int num = 9 % den;
        while (num) {
            num = (num * 10 + 9) % den;
            periodSize++;
        }
    }

    return { prefixSize, periodSize };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int num, den;
    char slash;
    cin >> num >> slash >> den;

    cout << num / den;

    if (num % den == 0)
        return 0;

    num %= den;

    int g = gcd(num, den);
    num /= g;
    den /= g;

    auto [prefixSize, periodSize] = getFractionPartSizes(den);

    cout << ".";

    for (int i = 0; i < prefixSize; i++) {
        cout << num * 10 / den;
        num = num * 10 % den;
    }

    if (periodSize) {
        cout << "(";
        for (int i = 0; i < periodSize; i++) {
            cout << num * 10 / den;
            num = num * 10 % den;
        }
        cout << ")";
    }
}