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

    vector<int> l(4), r(4);
    for (int i = 0; i < 4; i++)
        cin >> l[i] >> r[i];

    int aNum = 0, aDen = 0;
    for (int i = l[0]; i <= r[0]; i++) {
        for (int j = l[1]; j <= r[1]; j++) {
            aNum += i + j;
            aDen++;
        }
    }

    int bNum = 0, bDen = 0;
    for (int i = l[2]; i <= r[2]; i++) {
        for (int j = l[3]; j <= r[3]; j++) {
            bNum += i + j;
            bDen++;
        }
    }

    if (aNum * bDen < bNum * aDen)
        cout << "Emma\n";
    else if (aNum * bDen == bNum * aDen)
        cout << "Tie\n";
    else
        cout << "Gunnar\n";
}