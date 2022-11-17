#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isLeap(int year) {
    return year % 400 == 0 || year % 4 == 0 && year % 100;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int year;
    cin >> year;

    cout << (isLeap(year) ? "YES" : "NO");
}