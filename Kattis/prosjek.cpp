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

    long long whole;
    char dot;
    string frac;
    cin >> whole >> dot >> frac;

    long long num = whole, den = 1;
    for (char c : frac) {
        num = num * 10 + c - '0';
        den *= 10;
    }

    long long d = gcd(num, den);
    num /= d;
    den /= d;

    vector<int> res(5);
    res[0] = den;

    num -= den;
    for (int i = 4; i; i--) {
        res[0] -= num / i;
        res[i] += num / i;
        num %= i;
    }

    for (int value : res)
        cout << value << " ";
}