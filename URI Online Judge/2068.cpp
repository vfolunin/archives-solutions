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

    int h1, h2, m;
    cin >> h1 >> h2 >> m;

    long long size = (h2 - h1) * 60;
    long long den = size * size;
    long long num = den - (size - m) * (size - m);

    long long g = gcd(num, den);
    num /= g;
    den /= g;

    cout << num << "/" << den << "\n";
}