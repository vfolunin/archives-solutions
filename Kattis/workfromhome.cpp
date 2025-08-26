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

    long long power, time, price;
    cin >> power >> time >> price;

    cout << (power * time * price + 6000000 - 1) / 6000000;
}