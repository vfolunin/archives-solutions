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

    string s;
    int upperPrice, lowerPrice;
    cin >> s >> upperPrice >> lowerPrice;

    int upperCost = 0, lowerCost = 0;
    for (char c : s) {
        if (islower(c))
            upperCost += upperPrice;
        else
            lowerCost += lowerPrice;
    }

    cout << min(upperCost, lowerCost);
}