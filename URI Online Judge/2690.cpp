#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string line;
    getline(cin, line);

    static string letter = "GQakuISblvEOYcmwFPZdnxJTeoyDNXfpzAKUgqCMWhrBLVisHRjt";
    static string digit  = "0000011111222222333333444445555556666677777888889999";

    for (int i = 0, k = 0; i < line.size() && k < 12; i++) {
        if (line[i] == ' ')
            continue;
        k++;
        cout << digit[letter.find(line[i])];
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    string line;
    getline(cin, line);

    for (int i = 0; i < n; i++)
        solve();
}