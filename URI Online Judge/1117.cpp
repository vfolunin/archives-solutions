#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<double> a;
    while (a.size() < 2) {
        double x;
        cin >> x;

        if (0 <= x && x <= 10)
            a.push_back(x);
        else
            cout << "nota invalida\n";
    }

    cout.precision(2);
    cout << "media = " << fixed << (a[0] + a[1]) / 2 << "\n";
}