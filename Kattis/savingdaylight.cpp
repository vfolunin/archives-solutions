#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string month, day, year;
    int h1, m1, h2, m2;
    char colon;
    if (!(cin >> month >> day >> year >> h1 >> colon >> m1 >> h2 >> colon >> m2))
        return 0;

    int t = (h2 * 60 + m2) - (h1 * 60 + m1);

    cout << month << " " << day << " " << year << " ";
    cout << t / 60 << " hours " << t % 60 << " minutes\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}