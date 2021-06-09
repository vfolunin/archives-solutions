#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int peopleCount, transactionCount;
    cin >> peopleCount >> transactionCount;

    if (!peopleCount && !transactionCount)
        return 0;

    map<string, int> accounts;
    for (int i = 0; i < peopleCount; i++) {
        string name;
        cin >> name;

        accounts[name];
    }

    for (int i = 0; i < transactionCount; i++) {
        string a, b;
        int money;
        cin >> a >> b >> money;

        accounts[a] -= money;
        accounts[b] += money;
    }

    set<pair<int, string>> sortedAccounts;
    for (auto &[name, money] : accounts)
        if (money)
            sortedAccounts.insert({ money, name });
    
    cout << "Case #" << test << "\n";
    while (!sortedAccounts.empty()) {
        auto [moneyA, a] = *--sortedAccounts.end();
        sortedAccounts.erase(--sortedAccounts.end());
        auto [moneyB, b] = *sortedAccounts.begin();
        sortedAccounts.erase(sortedAccounts.begin());

        int delta = min(moneyA, -moneyB);
        cout << a << " " << b << " " << delta << "\n";

        if (moneyA > delta)
            sortedAccounts.insert({ moneyA - delta, a });
        if (moneyB < -delta)
            sortedAccounts.insert({ moneyB + delta, b });
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}