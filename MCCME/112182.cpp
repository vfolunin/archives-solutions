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

    string bin;
    while (value > 1) {
        bin += value % 2 + '0';
        value /= 2;
    }
    bin += value + '0';
    reverse(bin.begin(), bin.end());

    cout << bin;
}