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

    int id1, count1, id2, count2;
    double price1, price2;
    cin >> id1 >> count1 >> price1;
    cin >> id2 >> count2 >> price2;

    double res = count1 * price1 + count2 * price2;

    cout.precision(2);
    cout << "VALOR A PAGAR: R$ " << fixed << res << "\n";
}