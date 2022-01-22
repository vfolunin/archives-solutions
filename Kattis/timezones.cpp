#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readTime() {
    string line;
    cin >> line;

    if (line == "midnight")
        return 0;
    if (line == "noon")
        return 12 * 60;

    stringstream ss(line);
    int h, m;
    char c;
    string period;
    ss >> h >> c >> m;
    cin >> period;

    return h % 12 * 60 + m + (period == "p.m." ? 12 * 60 : 0);
}

void writeTime(int t) {
    if (t == 0) {
        cout << "midnight\n";
        return;
    }

    if (t == 12 * 60) {
        cout << "noon\n";
        return;
    }

    int h = t % (12 * 60) / 60;
    cout << (h ? h : 12) << ":";
    cout << setw(2) << setfill('0') << t % 60 << " ";
    cout << (t < 12 * 60 ? "a.m.\n" : "p.m.\n");
}

void solve() {
    int t = readTime();
    string a, b;
    cin >> a >> b;
    cin.ignore();

    static map<string, int> delta = {
        { "UTC", 0 }, { "GMT", 0 }, { "BST", 60 }, { "IST", 60 },
        { "WET", 0 }, { "WEST", 60 }, { "CET", 60 }, { "CEST", 120 },
        { "EET", 120 }, { "EEST", 180 }, { "MSK", 180 }, { "MSD", 240 },
        { "AST", -240 }, { "ADT", -180 }, { "NST", -210 }, { "NDT", -150 },
        { "EST", -300 }, { "EDT", -240 }, { "CST", -360 }, { "CDT", -300 },
        { "MST", -420 }, { "MDT", -360 }, { "PST", -480 }, { "PDT", -420 },
        { "HST", -600 }, { "AKST", -540 }, { "AKDT", -480 }, { "AEST", 600 },
        { "AEDT", 660 }, { "ACST", 570 }, { "ACDT", 630 }, { "AWST", 4800 }
    };

    t -= delta[a];
    t += delta[b];
    t = (t % (24 * 60) + 24 * 60) % (24 * 60);

    writeTime(t);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}