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

    string day, month, year;
    cin >> day >> month >> month >> year;
    month = month.substr(1);

    vector<string> months = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
    month = to_string(find(months.begin(), months.end(), month) - months.begin() + 1);

    cout << "20" << year << "-" << string(2 - month.size(), '0') << month << "-" << day;
}