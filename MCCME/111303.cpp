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

    char l, r;
    cin >> l >> r;

    for (char c = l; c <= r; c++)
        cout << c;
}