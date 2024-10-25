#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int grundy(int value) {
    value %= 5;
    if (value <= 1)
        return 0;
    else if (value <= 3)
        return 1;
    else
        return 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    int res = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        res ^= grundy(value);
    }

    cout << (res ? "Rybka" : "Watson");
}