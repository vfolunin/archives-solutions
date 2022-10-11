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

    int aNum, aDen, bNum, bDen;
    cin >> aNum >> aDen >> bNum >> bDen;

    int num = aNum * bDen + bNum * aDen, den = aDen * bDen;
    int d = gcd(num, den);
    num /= d;
    den /= d;

    cout << num << " " << den;
}