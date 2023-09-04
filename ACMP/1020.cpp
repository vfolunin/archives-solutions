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

    long long value;
    cin >> value;

    int bit = 0;
    while ((value & (1LL << bit)) == 0)
        bit++;
    cout << (1LL << bit) << " ";

    bit = 60;
    while ((value & (1LL << bit)) == 0)
        bit--;
    cout << (1LL << bit);
}