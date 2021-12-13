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

    int day, price, delta, dayCount;
    cin >> day >> price >> delta >> dayCount;

    if (dayCount % 2) {
        if (day % 2)
            price += delta;
        else
            price -= delta;
    }

    cout << price << "\n";
}