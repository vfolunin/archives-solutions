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

    int value, l, r;
    cin >> value >> l >> r;

    if (l > r)
        swap(l, r);

    cout << (l <= value && value <= r ? "SIM" : "NAO");
}