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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int count = b - a;
    int price = c * 100 + d;
    int cost = count * price;

    cout << count << "\n" << cost / 100 << " " << cost % 100;
}