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

    int debt, percent, payment;
    cin >> debt >> percent >> payment;

    double curDebt = debt;
    int paymentCount = 0;

    for (int i = 0; 1; i++) {
        curDebt *= 1 + (percent / 100.0);
        if (i % 7 == 6) {
            paymentCount++;
            if (curDebt <= payment) {
                cout.precision(2);
                cout << paymentCount << " " << fixed << curDebt;
                break;
            } else {
                curDebt -= payment;
                if (curDebt >= debt) {
                    cout << -1;
                    break;
                }
            }
        }
    }
}