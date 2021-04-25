#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string n;
    if (!(cin >> n))
        return 0;

    static vector<string> res = {
        "5.5957541127",
        "1.7320508076",
        "-0.2679491924",
        "-1.4226497308",
        "-2.5773502692"
    };

    if (n == "0" || n == "1" || n == "2")
        cout << res[stoi(n)] << "\n";
    else
        cout << res[4 - n.back() % 2] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}