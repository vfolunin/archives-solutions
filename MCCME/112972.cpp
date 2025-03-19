#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("e.in", "r", stdin);
    freopen("e.out", "w", stdout);

    long long n;
    cin >> n;

    cout << n / 9 * 81 + (n % 9) * (n % 9);
}