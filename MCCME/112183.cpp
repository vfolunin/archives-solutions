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

    int value;
    cin >> value;

    if (value < 0) {
        cout << "-";
        value = -value;
    }

    string oct;
    while (value > 7) {
        oct += value % 8 + '0';
        value /= 8;
    }
    oct += value + '0';
    reverse(oct.begin(), oct.end());

    cout << oct;
}