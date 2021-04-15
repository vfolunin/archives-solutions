#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int battlefieldCount, greenCount, blueCount;
    cin >> battlefieldCount >> greenCount >> blueCount;

    multiset<int> green, blue;
    for (int i = 0; i < greenCount; i++) {
        int x;
        cin >> x;
        green.insert(x);
    }
    for (int i = 0; i < blueCount; i++) {
        int x;
        cin >> x;
        blue.insert(x);
    }

    while (!green.empty() && !blue.empty()) {
        vector<pair<int, int>> battles;
        for (int i = 0; i < battlefieldCount && !green.empty() && !blue.empty(); i++) {
            battles.push_back({ *--green.end(), *--blue.end() });
            green.erase(--green.end());
            blue.erase(--blue.end());
        }

        for (auto [g, b] : battles) {
            if (g > b)
                green.insert(g - b);
            else if (g < b)
                blue.insert(b - g);
        }
    }

    if (test)
        cout << "\n";
    if (green.empty() && blue.empty()) {
        cout << "green and blue died\n";
    } else if (!green.empty()) {
        cout << "green wins\n";
        for (auto it = green.rbegin(); it != green.rend(); it++)
            cout << *it << "\n";
    } else {
        cout << "blue wins\n";
        for (auto it = blue.rbegin(); it != blue.rend(); it++)
            cout << *it << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}