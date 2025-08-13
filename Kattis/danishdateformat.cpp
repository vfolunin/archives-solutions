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

    int month, day, year;
    char slash;
    cin >> month >> slash >> day >> slash >> year;

    vector<string> monthName = {
        "januar", "februar", "marts", "april", "maj", "juni",
        "juli", "august", "september", "oktober", "november", "december"
    };

    cout << day << ". " << monthName[month - 1] << " " << year;
}