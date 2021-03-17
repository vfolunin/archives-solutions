#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int leapsTo(int d, int m, int y) {
    int res = y / 4 - y / 100 + y / 400;
    if ((y % 400 == 0 || y % 4 == 0 && y % 100) && (m == 1 || m == 2 && d < 29))
        res--;
    return res;
}

int monthNumber(const string &name) {
    static vector<string> names = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return find(names.begin(), names.end(), name) - names.begin() + 1;
}

void solve(int test) {
    string month, comma;
    int day, year;

    cin >> month >> day >> comma >> year;
    int leaps = -leapsTo(day - 1, monthNumber(month), year);

    cin >> month >> day >> comma >> year;
    leaps += leapsTo(day, monthNumber(month), year);

    cout << "Case " << test << ": " << leaps << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}