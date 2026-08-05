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

    cout << (year % 400 == 0 || year % 100 && year % 4 == 0 ? "True" : "False");
}