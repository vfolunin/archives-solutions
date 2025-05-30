#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int markCount;
    cin >> markCount;

    double num = 0, den = 0;
    for (int i = 0; i < markCount; i++) {
        int count;
        char mark;
        cin >> count >> mark;

        static string marks = "SABCDE";
        num += count * (10 - marks.find(mark));
        den += count;
    }

    cout.precision(2);
    cout << fixed << num / den << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}