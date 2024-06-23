#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve2() {
    vector<int> a(5);
    for (int &value : a) {
        cin >> value;
        value = value <= 127;
    }

    if (count(a.begin(), a.end(), 1) == 1)
        cout << (char)(find(a.begin(), a.end(), 1) - a.begin() + 'A') << "\n";
    else
        cout << "*\n";
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    for (int i = 0; i < n; i++)
        solve2();
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}