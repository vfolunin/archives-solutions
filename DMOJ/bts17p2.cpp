#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    double res = 1;
    for (int i = 0; i < size; i++) {
        double num, den;
        cin >> num >> den;

        res *= (den - num) / den;
    }

    cout.precision(10);
    cout << fixed << res;
}