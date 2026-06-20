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

    long long price, money, count;
    cin >> price >> money >> count;

    cout << max(price * (count * (count + 1) / 2) - money, 0LL);
}