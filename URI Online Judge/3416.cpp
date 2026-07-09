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

    long long count, den, num;
    cin >> count >> den >> num;

    num *= count;
    den *= 1000;

    cout << (num + den - 1) / den * den / 1000 << "\n";
}