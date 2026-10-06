#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isLeap(int year) {
    return year % 400 == 0 || year % 100 != 0 && year % 4 == 0;
}

int days(int year) {
    return 365 + isLeap(year);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int year;
    cin >> year;

    int resYear = year + 1, totalDays = days(year);
    while (isLeap(year) != isLeap(resYear) || totalDays % 7) {
        totalDays += days(resYear);
        resYear++;
    }

    cout << resYear;
}