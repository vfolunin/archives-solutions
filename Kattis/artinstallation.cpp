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

    int needR, needG, needB;
    cin >> needR >> needG >> needB;

    int r, g, b, rg, gb;
    cin >> r >> g >> b >> rg >> gb;

    needR = max(needR - r, 0);
    needG = max(needG - g, 0);
    needB = max(needB - b, 0);

    if (needR > rg) {
        cout << -1;
        return 0;
    }
    rg -= needR;

    if (needB > gb) {
        cout << -1;
        return 0;
    }
    gb -= needB;

    cout << (needG <= rg + gb ? needR + needG + needB : -1);
}