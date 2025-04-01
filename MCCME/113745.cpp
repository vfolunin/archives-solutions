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

    int totalCount = 0, totalCost = 0;
    for (int i = 0; i < size; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int count = b - a;
        int price = c * 100 + d;

        totalCount += count;
        totalCost += count * price;
    }

    cout << totalCount << "\n" << totalCost / 100 << " " << totalCost % 100;
}