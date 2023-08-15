#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> getFractionPartSizes(int num, int den) {
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
        num = 9 % den;
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

    int den;
    cin >> den;

    auto [prefixSize, periodSize] = getFractionPartSizes(1, den);

    cout << prefixSize << " " << max(periodSize, 1);
}