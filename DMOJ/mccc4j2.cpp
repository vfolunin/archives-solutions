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

    int size, ah, bh;
    cin >> size >> ah >> bh;

    int at = 0, bt = 0;
    for (int i = 0; i < size; i++) {
        int a, b;
        cin >> a >> b;

        at += a >= ah;
        bt += b >= bh;
    }

    if (at < bt)
        cout << "Andrew wins!\n";
    else if (at == bt)
        cout << "Tie!\n";
    else
        cout << "Tommy wins!\n";
}