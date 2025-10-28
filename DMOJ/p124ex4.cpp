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

    double percent;
    long long year1, population, year2;
    cin >> percent >> year1 >> population >> year2;

    cout << (long long)ceil(population * pow(1 + percent / 100, year2 - year1));
}