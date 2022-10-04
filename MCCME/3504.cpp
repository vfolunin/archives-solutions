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

    if (year % 400 == 0 || year % 4 == 0 && year % 100)
        cout << "YES";
    else
        cout << "NO";
}