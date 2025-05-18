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

    if (year % 4)
        cout << 1;
    else if (year % 100)
        cout << 2;
    else
        cout << 3;
}