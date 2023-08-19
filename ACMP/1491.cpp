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

    long long coinCount, coinWeight, delta;
    cin >> coinCount >> coinWeight >> delta;

    cout << coinCount * delta / (delta - 1);
}