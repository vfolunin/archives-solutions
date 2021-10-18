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

    int opCount, balance;
    cin >> opCount >> balance;

    int minBalance = balance;

    for (int i = 0; i < opCount; i++) {
        int delta;
        cin >> delta;
        balance += delta;
        minBalance = min(minBalance, balance);
    }

    cout << minBalance << "\n";
}