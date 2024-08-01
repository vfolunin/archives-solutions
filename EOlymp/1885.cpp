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

    vector<int> price = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
    int res = n < 0;
    
    for (n = abs(n); n > 9; n /= 10)
        res += price[n % 10];
    res += price[n];

    cout << res;
}