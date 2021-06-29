#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int a, b;
    if (!(cin >> a >> b))
        return 0;

    const long long HOUR = 60 * 60, DAY = 24 * HOUR;

    long long delta = abs(a - b);
    long long seconds = (DAY / 2) * (DAY - a) / delta % (DAY / 2) + 30;

    long long hours = seconds / HOUR;
    if (!hours)
        hours = 12;

    long long minutes = seconds % HOUR / 60;

    cout << a << " " << b << " ";
    cout << setw(2) << setfill('0') << hours << ":";
    cout << setw(2) << setfill('0') << minutes << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}