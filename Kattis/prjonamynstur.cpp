#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    unordered_map<char, int> price;
    price['.'] = 20;
    price['O'] = 10;
    price['\\'] = 25;
    price['/'] = 25;
    price['A'] = 35;
    price['^'] = 5;
    price['v'] = 22;

    int res = 0;
    for (char c; cin >> c; )
        res += price[c];

    cout << res;
}