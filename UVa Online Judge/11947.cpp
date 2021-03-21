#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Date {
    int d, m, y;

    static bool isLeap(int y) {
        return y % 400 == 0 || y % 4 == 0 && y % 100;
    }

    static int days(int m, int y) {
        static int d[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return d[m] + (m == 2 && isLeap(y));
    }

    void inc() {
        d++;
        if (d > days(m, y)) {
            d = 1;
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }
    }
};

void solve(int test) {
    string s;
    cin >> s;

    Date date;
    date.d = stoi(s.substr(2, 2));
    date.m = stoi(s.substr(0, 2));
    date.y = stoi(s.substr(4));

    for (int i = 0; i < 40 * 7; i++)
        date.inc();

    static vector<Date> from = {
        {1, 1, 0},
        {21, 1, 0}, {20, 2, 0}, {21, 3, 0}, {21, 4, 0},
        {22, 5, 0}, {22, 6, 0}, {23, 7, 0}, {22, 8, 0},
        {24, 9, 0}, {24, 10, 0}, {23, 11, 0}, {23, 12, 0}
    };
    static vector<string> sign = {
        "capricorn",
        "aquarius", "pisces", "aries", "taurus",
        "gemini", "cancer", "leo", "virgo",
        "libra", "scorpio", "sagittarius", "capricorn"
    };

    int i = 12;
    while (from[i].m > date.m || from[i].m == date.m && from[i].d > date.d)
        i--;

    cout << test << " ";
    cout << setw(2) << setfill('0') << date.m << "/";
    cout << setw(2) << setfill('0') << date.d << "/"; 
    cout << setw(4) << setfill('0') << date.y << " "; 
    cout << sign[i] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int test = 1; test <= n; test++)
        solve(test);
}