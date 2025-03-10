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

    int peopleCount, transactionCount;
    cin >> peopleCount >> transactionCount;

    vector<int> accounts(peopleCount);
    for (int i = 0; i < transactionCount; i++) {
        int a, b, money;
        cin >> a >> b >> money;
        a--;
        b--;

        accounts[a] -= money;
        accounts[b] += money;
    }

    int res = 0;
    for (int i = 0; i < peopleCount; i++)
        if (accounts[i] > 0)
            res += accounts[i];

    cout << res;
}