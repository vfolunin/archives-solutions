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

    int size;
    cin >> size;

    int cost = 0;
    for (int i = 0; i < size; i++) {
        int have, need, price;
        cin >> have >> need >> price;

        if (have < need)
            cost += (need - have) * price;
    }

    cout << cost;
}