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

    int limit, price1, price2, time;
    cin >> limit >> price1 >> price2 >> time;

    cout << min(time, limit) * price1 + max(time - limit, 0) * price2;
}