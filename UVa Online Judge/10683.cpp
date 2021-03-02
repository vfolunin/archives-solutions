#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string line;
    if (!(cin >> line))
        return 0;

    long long h = stoll(line.substr(0, 2));
    long long m = stoll(line.substr(2, 2));
    long long s = stoll(line.substr(4, 2));
    long long c = stoll(line.substr(6, 2));
    long long t = ((h * 60 + m) * 60 + s) * 100 + c;
    t = t * (10 * 100 * 100) / (24 * 60 * 60);

    cout << t / (100 * 100 * 100);
    t %= 100 * 100 * 100;
    cout << setw(2) << setfill('0') << t / (100 * 100);
    t %= 100 * 100;
    cout << setw(2) << setfill('0') << t / 100;
    t %= 100;
    cout << setw(2) << setfill('0') << t << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}