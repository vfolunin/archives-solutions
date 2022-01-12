#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int cityCount;
    cin >> cityCount;

    set<string> cities;
    for (int i = 0; i < cityCount; i++) {
        string city;
        cin >> city;
        cities.insert(city);
    }

    cout << cities.size() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}