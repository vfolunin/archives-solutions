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

    int n;
    cin >> n;

    n = (n + 59) / 60;

    int price = 64;
    long long cost = 1;

    for (; n && price > 1; n--, price /= 2)
        cost += price;
    cost += n;

    cout << cost;
}