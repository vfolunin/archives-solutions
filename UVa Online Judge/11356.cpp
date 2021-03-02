#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isLeap(int y) {
    return y % 400 == 0 || y % 4 == 0 && y % 100;
}

void solve(int test) {
    int y;
    cin >> y;

    string monthStr;
    cin.ignore();
    while (1) {
        char c;
        cin >> c;
        if (c == '-')
            break;
        monthStr += c;
    }
    
    int d, n;
    cin >> d >> n;

    static vector<string> monthName = { "",
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int m = find(monthName.begin(), monthName.end(), monthStr) - monthName.begin();

    vector<int> daysInMonth = { 0, 31, 28 + isLeap(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    while (n--) {
        d++;
        if (d > daysInMonth[m]) {
            d = 1;
            m++;
            if (m == 13) {
                m = 1;
                y++;
                daysInMonth[2] = 28 + isLeap(y);
            }
        }
    }

    cout << "Case " << test << ": ";
    cout << y << "-" << monthName[m] << "-" << setw(2) << setfill('0') << d << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}