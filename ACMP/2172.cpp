#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double num, den;
    cin >> num >> den;

    double a = den - num;
    double b = -(num + 2 * den);
    double c = den - num;

    cout << fixed << (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}