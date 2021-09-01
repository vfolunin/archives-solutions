#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    set<int> ignored;
    map<int, set<int>> sLock;
    map<int, int> xLock;

    if (test)
        cout << "\n";

    while (1) {
        char mode;
        cin >> mode;

        if (mode == '#')
            break;

        int transaction, item;
        cin >> transaction >> item;

        if (ignored.count(transaction)) {
            cout << "IGNORED\n";
            continue;
        }

        if (mode == 'S') {
            if (xLock.count(item) && xLock[item] != transaction) {
                cout << "DENIED\n";
                ignored.insert(transaction);
            } else {
                cout << "GRANTED\n";
                sLock[item].insert(transaction);
            }
        } else {
            if (xLock.count(item) && xLock[item] != transaction ||
                sLock[item].size() > 1 || sLock[item].size() == 1 && *sLock[item].begin() != transaction) {
                cout << "DENIED\n";
                ignored.insert(transaction);
            } else {
                cout << "GRANTED\n";
                xLock[item] = transaction;
            }
        }
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