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

    double money, percent;
    int count;
    cin >> money >> percent >> count;

    cout.precision(2);
    for (int i = 0; i <= count; i++) {
        cout << i << " " << fixed << money << "\n";
        money *= 1 + percent / 100;
    }
}