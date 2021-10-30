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

    double num = 0, den = 0;

    string name;
    while (getline(cin, name)) {
        double dist;
        cin >> dist;
        cin.ignore();

        num += dist;
        den++;
    }

    cout.precision(1);
    cout << fixed << num / den << "\n";
}