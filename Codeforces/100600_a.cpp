#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int aDen, bNum, bDen, aNum;
    cin >> aDen >> bNum >> bDen >> aNum;

    int a = (aNum + aDen - 1) / aDen;
    int b = (bNum + bDen - 1) / bDen;

    if (a < b)
        cout << "WIN";
    else if (a == b)
        cout << "DRAW";
    else
        cout << "LOSE";
}