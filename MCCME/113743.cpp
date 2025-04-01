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

    int a1, b1, c1, d1;
    cin >> a1 >> b1 >> c1 >> d1;

    int a2, b2, c2, d2;
    cin >> a2 >> b2 >> c2 >> d2;

    int count1 = b1 - a1;
    int price1 = c1 * 100 + d1;

    int count2 = b2 - a2;
    int price2 = c2 * 100 + d2;

    int count = count1 + count2;
    int cost = count1 * price1 + count2 * price2;

    cout << count << "\n" << cost / 100 << " " << cost % 100;
}