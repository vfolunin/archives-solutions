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

    int dayCount, monthCount, weekdayCount, day, month, year;
    cin >> dayCount >> monthCount >> weekdayCount >> day >> month >> year;

    year = (year - 1) % weekdayCount;
    month--;
    day--;

    cout << (char)(((year * monthCount + month) * dayCount + day) % weekdayCount + 'a');
}