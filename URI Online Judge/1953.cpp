#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    map<string, int> count;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s >> s;
        if (s != "EPR" && s != "EHD")
            s = "INTRUSOS";
        count[s]++;
    }

    for (string s : {"EPR", "EHD", "INTRUSOS"})
        cout << s << ": " << count[s] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}