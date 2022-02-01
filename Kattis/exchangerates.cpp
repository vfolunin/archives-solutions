#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int dayCount;
    cin >> dayCount;

    if (!dayCount)
        return 0;

    int caCents = 100000, usCents = 0;
    for (int i = 0; i < dayCount; i++) {
        double rate;
        cin >> rate;

        int nextCaCents = usCents * rate * 0.97;
        int nextUsCents = caCents / rate * 0.97;

        caCents = max(caCents, nextCaCents);
        usCents = max(usCents, nextUsCents);
    }

    cout << setw(1) << setfill('0') << caCents / 100 << ".";
    cout << setw(2) << setfill('0') << caCents % 100 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}