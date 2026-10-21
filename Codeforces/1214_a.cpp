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

    int rub, usd, eur;
    cin >> rub >> usd >> eur;
    eur *= 5;

    int res = rub;
    for (int eurCount = 0; eurCount * eur <= rub; eurCount++)
        res = min(res, (rub - eurCount * eur) % usd);

    cout << res;
}