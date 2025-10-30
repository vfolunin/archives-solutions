#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double percent;
    int count, year, limit;
    cin >> percent >> count >> year >> limit;

    while (count < limit) {
        count = ceil(count * (1 + percent / 100));
        year++;
    }

    cout << year;
}