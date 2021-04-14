#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int num, den;
    cin >> num >> den;

    if (!num && !den)
        return 0;

    string frac = ".";
    map<int, int> seen;
    int cycle = 0;

    for (int i = 0; num; i++) {
        if (seen.count(num)) {
            cycle = i - seen[num];
            break;
        }
        seen[num] = i;
        frac += '0' + num * 10 / den;
        num = num * 10 % den;
    }

    for (int i = 0; i < frac.size(); i++) {
        cout << frac[i];
        if (i % 50 == 49 || i + 1 == frac.size())
            cout << "\n";
    }
    if (cycle)
        cout << "The last " << cycle << " digits repeat forever.\n";
    else
        cout << "This expansion terminates.\n";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}