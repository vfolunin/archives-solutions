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

    if (year < 1896 || year == 1916 || year == 1940 || year == 1944 || year % 2)
        cout << "nothing";
    else if (1924 <= year && year <= 1992 && year % 4 == 0)
        cout << "winter summer";
    else if (year % 4 == 0 || year == 1906)
        cout << "summer";
    else
        cout << "winter";
}