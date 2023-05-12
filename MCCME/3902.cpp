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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int startYear;
    cin >> startYear;

    int curYear = startYear, days = 0;
    do {
        days += 365 + isLeap(curYear);
        curYear++;
    } while (days % 7 || isLeap(startYear) != isLeap(curYear));

    cout << curYear;
}