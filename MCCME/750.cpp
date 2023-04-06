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

    int value, size;
    cin >> value >> size;

    for (int bit = size - 1; bit >= 0; bit--)
        cout << (bool)(value & (1 << bit));
}