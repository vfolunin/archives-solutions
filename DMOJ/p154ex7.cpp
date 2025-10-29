#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isGood(int value) {
    int sum = 0;
    for (char c : to_string(value)) {
        int digit = c - '0';
        sum += digit * digit * digit;
    }
    return sum == value;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    for (int value = l; value <= r; value++)
        if (isGood(value))
            cout << value << "\n";
}