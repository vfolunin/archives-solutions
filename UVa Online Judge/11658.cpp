#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int read() {
    int whole, frac;
    char dot;
    cin >> whole >> dot >> frac;
    return whole * 100 + frac;
}

bool solve() {
    int stockholderCount, stockholderId;
    cin >> stockholderCount >> stockholderId;

    if (!stockholderCount)
        return 0;
    stockholderId--;

    vector<int> stock(stockholderCount);
    for (int &s : stock)
        s = read();

    int ownStock = stock[stockholderId];
    stock.erase(stock.begin() + stockholderId);
    
    vector<int> can(10001);
    can[ownStock] = 1;

    for (int s : stock)
        for (int sum = 10000; sum >= ownStock + s; sum--)
            can[sum] |= can[sum - s];

    int shareStock = 5001;
    while (!can[shareStock])
        shareStock++;

    cout.precision(2);
    cout << fixed << 100.0 * ownStock / shareStock << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}