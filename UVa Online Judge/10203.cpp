#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int x, y;
    cin >> x >> y;
    cin.ignore();

    double dist = 0;
    while (1) {
        string line;
        if (!getline(cin, line) || line.empty())
            break;

        stringstream ss(line);
        double x1, y1, x2, y2;
        ss >> x1 >> y1 >> x2 >> y2;

        dist += 2 * hypot(x1 - x2, y1 - y2) / 1000;
    }

    int minutes = round(dist / 20 * 60);
    int hours = minutes / 60;
    minutes %= 60;

    if (test)
        cout << "\n";
    cout << hours << ":" << setw(2) << setfill('0') << minutes << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}