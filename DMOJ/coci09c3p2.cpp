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

    int price, zeroCount;
    cin >> price >> zeroCount;

    int nominal = 1;
    for (int i = 0; i < zeroCount; i++)
        nominal *= 10;

    if (nominal == 1)
        cout << price;
    else if (price % nominal < nominal / 2)
        cout << price / nominal * nominal;
    else
        cout << (price / nominal + 1) * nominal;
}