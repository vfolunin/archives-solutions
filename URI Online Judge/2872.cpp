#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int start;
    if (!(cin >> start))
        return 0;

    vector<int> ids;
    while (1) {
        string package;
        cin >> package;

        if (package == "0")
            break;

        cin >> ids.emplace_back();
    }

    sort(ids.begin(), ids.end());

    for (int id : ids)
        cout << "Package " << setw(3) << setfill('0') << id << "\n";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}