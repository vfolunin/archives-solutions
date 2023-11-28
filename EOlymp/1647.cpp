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

    int value, bitCount;
    cin >> value >> bitCount;

    value &= ~((1 << bitCount) - 1);

    cout << value;
}