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

    for (int bit = 0; bit < 30; bit++)
        if (value & (1 << bit))
            cout << (1 << bit) << " ";
}