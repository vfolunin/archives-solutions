#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long leapYearCountTo(long long year) {
    return year / 4 - year / 100 + year / 400;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long year;
    cin >> year;

    if (year % 400 == 0 || year % 4 == 0 && year % 100)
        cout << leapYearCountTo(year) - leapYearCountTo(2020);
    else
        cout << "Neibb";
}