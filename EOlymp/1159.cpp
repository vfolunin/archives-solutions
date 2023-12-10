#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int daysInMonth(int month) {
    vector<int> days = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return days[month];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int sum;
    cin >> sum;

    for (int m = 1; m <= 12; m++) {
        for (int d = 1; d <= daysInMonth(m); d++) {
            if (d * 12 + m * 31 == sum) {
                cout << setw(2) << setfill('0') << d << "/";
                cout << setw(2) << setfill('0') << m;
                break;
            }
        }
    }
}