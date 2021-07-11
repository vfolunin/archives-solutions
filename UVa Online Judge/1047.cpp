#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int towerCount, towerNeed;
    cin >> towerCount >> towerNeed;

    if (!towerCount)
        return 0;

    vector<int> customers(towerCount);
    for (int &c : customers)
        cin >> c;

    int commonAreaCount;
    cin >> commonAreaCount;

    vector<pair<vector<int>, int>> commonAreaCustomers(commonAreaCount);
    for (auto &[towers, customers] : commonAreaCustomers) {
        int towerCount;
        cin >> towerCount;
        towers.resize(towerCount);
        for (int &t : towers) {
            cin >> t;
            t--;
        }
        cin >> customers;
    }

    string mask = string(towerNeed, '0') + string(towerCount - towerNeed, '1'), bestMask;
    int bestRes = -1;
    do {
        int curRes = 0;
        for (int i = 0; i < towerCount; i++)
            if (mask[i] == '0')
                curRes += customers[i];

        for (auto &[towers, customers] : commonAreaCustomers) {
            int ones = 0;
            for (int t : towers)
                ones += mask[t] == '0';
            curRes -= customers * max(0, ones - 1);
        }

        if (bestRes == -1 || bestRes < curRes) {
            bestRes = curRes;
            bestMask = mask;
        }
    } while (next_permutation(mask.begin(), mask.end()));

    cout << "Case Number  " << test << "\n";
    cout << "Number of Customers: " << bestRes << "\n";
    cout << "Locations recommended:";
    for (int i = 0; i < bestMask.size(); i++)
        if (bestMask[i] == '0')
            cout << " " << i + 1;
    cout << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}