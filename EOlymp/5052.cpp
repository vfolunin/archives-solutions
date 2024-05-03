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

    int value, bit;
    cin >> value >> bit;
    bit--;

    cout << ((value & (1 << bit)) ? "YES" : "NO");
}