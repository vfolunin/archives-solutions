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

    int rolls, sides, add;
    char c;
    cin >> rolls >> c >> sides >> c >> add;

    cout << fixed << (sides + 1) / 2.0 * rolls + add;
}