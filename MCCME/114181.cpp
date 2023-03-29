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

    int price, percent, money;
    cin >> price >> percent >> money;

    price *= 100 + percent;
    money *= 100;

    cout << money / price;
}