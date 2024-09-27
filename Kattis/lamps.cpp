#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int cost(int hours, int electricityPrice, int power, int life, int lampPrice, int days) {
    hours *= days;
    return power * hours * electricityPrice + (hours + life - 1) / life * lampPrice * 1e5;
}

bool can(int hours, int electricityPrice, int days) {
    return cost(hours, electricityPrice, 60, 1000, 5, days) > cost(hours, electricityPrice, 11, 8000, 60, days);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int hours, electricityPrice;
    cin >> hours >> electricityPrice;

    int l = 0, r = 1;
    while (!can(hours, electricityPrice, r))
        r *= 2;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(hours, electricityPrice, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}