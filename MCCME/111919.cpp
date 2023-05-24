#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int daysInMonth(int m) {
    vector<int> days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return days[m];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int d, m;
    cin >> d >> m;

    d++;
    if (d > daysInMonth(m))
        d = 1;

    cout << d;
}