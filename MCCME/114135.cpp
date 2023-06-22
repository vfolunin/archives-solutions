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

    long long a, b, price;
    cin >> a >> b >> price;

    cout << (a + b) / price << " ";

    if (a % price + b % price < price)
        cout << 0;
    else
        cout << (price - max(a % price, b % price)) % price;
}