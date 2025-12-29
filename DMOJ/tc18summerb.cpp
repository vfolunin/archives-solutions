#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int orValue, andValue, xorValue;
    cin >> orValue >> andValue >> xorValue;

    if (orValue >= andValue && (orValue ^ andValue) == xorValue)
        cout << (1LL << ones(xorValue));
    else
        cout << 0;
}