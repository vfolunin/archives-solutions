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

    int cupCount;
    cin >> cupCount;

    vector<pair<int, string>> cups(cupCount);
    for (auto &[size, color] : cups) {
        string a, b;
        cin >> a >> b;

        if (isdigit(a[0])) {
            size = stoi(a);
            color = b;
        } else {
            size = 2 * stoi(b);
            color = a;
        }
    }

    sort(cups.begin(), cups.end());

    for (auto &[size, color] : cups)
        cout << color << "\n";
}