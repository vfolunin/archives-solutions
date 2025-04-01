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

    int a3, b3, c3, d3;
    cin >> a3 >> b3 >> c3 >> d3;

    int count1 = b1 - a1;
    int price1 = c1 * 100 + d1;

    int count2 = b2 - a2;
    int price2 = c2 * 100 + d2;

    int count3 = b3 - a3;
    int price3 = c3 * 100 + d3;

    int count = count1 + count2 + count3;
    int cost = count1 * price1 + count2 * price2 + count3 * price3;

    cout << count << "\n" << cost / 100 << " " << cost % 100;
}