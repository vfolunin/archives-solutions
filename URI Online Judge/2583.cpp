#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int opCount;
    cin >> opCount;

    set<string> items;
    for (int i = 0; i < opCount; i++) {
        string item, op;
        cin >> item >> op;

        if (op == "chirrin")
            items.insert(item);
        else if (op == "chirrion")
            items.erase(item);
    }

    cout << "TOTAL\n";
    for (const string &item : items)
        cout << item << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}