#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isLeap(int year) {
    return year % 400 == 0 || year % 100 && year % 4 == 0;
}

int daysInMonth(int month, int year) {
    vector<int> days = { 0, 31, 28 + isLeap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return days[month];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int month, year;
    cin >> month >> year;

    cout << daysInMonth(month, year);
}