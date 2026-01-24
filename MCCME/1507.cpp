#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<double> card(3), envelope(2);
    for (double &value : card)
        cin >> value;
    for (double &value : envelope)
        cin >> value;

    sort(card.rbegin(), card.rend());
    double a = card[1], b = card[2];

    sort(envelope.rbegin(), envelope.rend());
    double c = envelope[0], d = envelope[1];

    if (a <= c && b <= d) {
        cout << "YES";
        return 0;
    }

    double l = 0, r = asin(1.0);
    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        if (a * cos(m) + b * sin(m) > c)
            l = m;
        else
            r = m;
    }

    cout << (a * sin(l) + b * cos(l) <= d ? "YES" : "NO");
}