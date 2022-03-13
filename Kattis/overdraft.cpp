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

    int transactionCount;
    cin >> transactionCount;

    int curBalance = 0, startBalance = 0;
    for (int i = 0; i < transactionCount; i++) {
        int transaction;
        cin >> transaction;
        curBalance += transaction;
        startBalance = max(startBalance, -curBalance);
    }

    cout << startBalance;
}