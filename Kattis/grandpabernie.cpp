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

    int tripCount;
    cin >> tripCount;

    map<string, vector<int>> trips;
    for (int i = 0; i < tripCount; i++) {
        string country;
        int year;
        cin >> country >> year;
        trips[country].push_back(year);
    }

    for (auto &[country, years] : trips)
        sort(years.begin(), years.end());

    int queryCount;
    cin >> queryCount;
    
    for (int i = 0; i < queryCount; i++) {
        string country;
        int index;
        cin >> country >> index;
        cout << trips[country][index - 1] << "\n";
    }
}