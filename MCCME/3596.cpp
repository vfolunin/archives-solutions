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

    int n;
    cin >> n;

    int bit = 30;
    while (!(n & (1 << bit)))
        bit--;

    cout << (1 << (bit + 1)) - 1 - n;
}