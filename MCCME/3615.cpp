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

    int p, a, b;
    cin >> p >> a >> b;

    int amount = a * 100 + b;
    amount += amount * p / 100;

    cout << amount / 100 << " " << amount % 100;
}