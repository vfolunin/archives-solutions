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

    long long money, limit1, limit2, price1, price2;
    cin >> money >> limit1 >> limit2 >> price1 >> price2;

    long long count1 = limit1;
    money -= count1 * price1;

    long long count2 = min(money / price2, limit2);
    money -= count2 * price2;
    count1 += money / price1;

    cout << count1 << " " << count2;
}