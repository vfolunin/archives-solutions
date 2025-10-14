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

    int month, day;
    cin >> month >> day;

    if (month == 2 && day == 18)
        cout << "Special";
    else if (month < 2 || month == 2 && day < 18)
        cout << "Before";
    else
        cout << "After";
}