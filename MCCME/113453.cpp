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

    int dayCount, monthCount, d, m;
    cin >> dayCount >> monthCount >> d >> m;

    int daysInMonth = dayCount / monthCount;
    int dayNumber = daysInMonth * (m - 1) + d - 1;

    monthCount++;
    daysInMonth = dayCount / monthCount;

    cout << dayNumber % daysInMonth + 1 << " " << dayNumber / daysInMonth + 1;
}