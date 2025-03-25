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

    long long base, zeros, index;
    cin >> base >> zeros >> index;

    long long res = index;
    for (int i = 0; i < zeros; i++)
        res *= base;

    cout << res;
}