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

    int year, weekDay;
    cin >> year >> weekDay;
    weekDay--;

    int days = 365 + isLeap(year);
    int res = 0;
    for (int i = 0; i < days; i++)
        res += (weekDay + i) % 7 >= 5;

    cout << res;
}