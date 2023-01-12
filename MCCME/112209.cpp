#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isGood(int value) {
    for (int digits = value; digits; digits /= 10)
        if (digits % 10 == 0 || value % (digits % 10))
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; i++)
        if (isGood(i))
            cout << i << " ";
}