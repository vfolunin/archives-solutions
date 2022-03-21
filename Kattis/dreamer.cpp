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

int daysInMonth(int m, int y) {
    vector<int> days = { 0, 31, 28 + isLeap(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return days[m];
}

void solve() {
    string ds, ms, ys;
    cin >> ds >> ms >> ys;

    string s = ds + ms + ys;
    sort(s.begin(), s.end());

    int dateCount = 0, minD, minM, minY;
    do {
        int d = stoi(s.substr(0, 2));
        int m = stoi(s.substr(2, 2));
        int y = stoi(s.substr(4));

        if (2000 <= y && 1 <= m && m <= 12 && 1 <= d && d <= daysInMonth(m, y)) {
            if (!dateCount || minY > y || minY == y && minM > m || minY == y && minM == m && minD > d) {
                minY = y;
                minM = m;
                minD = d;
            }
            dateCount++;
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << dateCount;
    if (dateCount) {
        cout << " " << setw(2) << setfill('0') << minD;
        cout << " " << setw(2) << setfill('0') << minM;
        cout << " " << setw(4) << setfill('0') << minY;
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}