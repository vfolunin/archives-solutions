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

    if (year == 1984)
        cout << "Literally 1984";
    else
        cout << "Not 1984... yet";
}