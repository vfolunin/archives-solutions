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

    int day, month, year;
    cin >> day >> month >> year;

    cout << year << "/";
    
    cout << day;
    if (day == 1 || day == 21 || day == 31)
        cout << "st/";
    else if (day == 2 || day == 22)
        cout << "nd/";
    else if (day == 3 || day == 23)
        cout << "rd/";
    else
        cout << "th/";

    vector<string> months = {
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };
    cout << months[month - 1];
}