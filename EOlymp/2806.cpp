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

    int res = n / 2;
    res += n / 3;
    res += n / 5;

    res -= n / 6;
    res -= n / 10;
    res -= n / 15;

    res += n / 30;

    cout << n - res;
}