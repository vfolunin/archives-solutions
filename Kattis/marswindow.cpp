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

    int year;
    cin >> year;

    int month = 2018 * 12 + 3;
    while (month / 12 < year)
        month += 26;

    cout << (month / 12 == year ? "yes" : "no");
}